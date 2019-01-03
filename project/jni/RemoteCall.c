#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include "Elflib.h"
#include "Process.h"
#include "Debugger.h"

#if defined(__arm__)
const char* libc_path = "/system/lib/libc.so";
const char* linker_path = "/system/bin/linker";

#elif defined(__aarch64__)
const char* libc_path = "/system/lib64/libc.so";
const char* linker_path = "/system/bin/linker64";

#endif

u8 RemoteCall_GetMemoryAddr(u2 tid, const char* path, const char* name)
{
	u8 file_offset = nm_get_all_sym_addr(path, name);
	u8 memory_start_addr = Process_ReadMemoryModuleAddr(tid, path, "r-xp");
	u8 sym_addr = memory_start_addr + file_offset;
	return sym_addr;
}

u8 RemoteCall_malloc(u2 tid, u4 size)
{
	u8 addr = RemoteCall_GetMemoryAddr(tid, libc_path, "malloc");
	return Debugger_Call(tid, addr, 1, size);
}

u8 RemoteCall_calloc(u2 tid, u4 n, u4 size)
{
	u8 addr = RemoteCall_GetMemoryAddr(tid, libc_path, "calloc");
	return Debugger_Call(tid, addr, 2, n, size);
}

u8 RemoteCall_free(u2 tid, u8 free_addr)
{
	u8 addr = RemoteCall_GetMemoryAddr(tid, libc_path, "free");
	return Debugger_Call(tid, addr, 1, free_addr);
}

u8 RemoteCall_NewString(u2 tid, const char* str)
{
	u8 str_addr = -1;
	u4 str_len = strlen(str);
	if ((str_addr = RemoteCall_calloc(tid, 1, str_len + 1)) < 0) 
	{
		return -1;
	} else {
		Debugger_setMemory(tid, str_addr, (u1*)str, str_len);
		return str_addr;
	}
}

u8 RemoteCall_puts(u2 tid, const char* str)
{
	u8 r_str = RemoteCall_NewString(tid, str);
	u8 addr = RemoteCall_GetMemoryAddr(tid, libc_path, "puts");
	u8 result = Debugger_Call(tid, addr, 1, r_str);
	RemoteCall_free(tid, r_str);
	return result;
}

u8 RemoteCall_dlopen(u2 tid, u8 path, int flag)
{
	u8 addr = RemoteCall_GetMemoryAddr(tid, linker_path, "__dl_dlopen");
	return Debugger_Call(tid, addr, 2, path, flag);
}

u8 RemoteCall_dlsym(u2 tid, u8 handle, u8 sym)
{
	u8 addr = RemoteCall_GetMemoryAddr(tid, linker_path, "__dl_dlsym");
	return Debugger_Call(tid, addr, 2, handle, sym);
}

u8 RemoteCall_dlclose(u2 tid, u8 handle)
{
	u8 addr = RemoteCall_GetMemoryAddr(tid, linker_path, "__dl_dlclose");
	return Debugger_Call(tid, addr, 1, handle);
}

int RemoteCall_SoInject(u2 tid, const char* so_name)
{
	const char* func_name = "Start";
	int flag = RTLD_NOW;
	puts("Start Inject!");
	u8 r_path = RemoteCall_NewString(tid, so_name);
	u8 r_name = RemoteCall_NewString(tid, func_name);
	if (r_path > 0 && func_name > 0) {
		u8 dl_handle = RemoteCall_dlopen(tid, r_path, flag);
		if (dl_handle > 0) {
			u8 dl_sym = RemoteCall_dlsym(tid, dl_handle, r_name);
			if (dl_sym > 0) {
				Debugger_Call(tid, dl_sym, 0);
				RemoteCall_dlclose(tid, dl_handle);
				RemoteCall_free(tid, r_path);
				RemoteCall_free(tid, r_name);
				puts("Inject Success!");
			} else {
			puts("Inject Fail:Remote Call dlsym fail!");
			return -3;
			}
		} else {
			puts("Inject Fail:Remote Call dlopen fail!");
			return -2;
		}
	} else {
		puts("Inject Fail:Remote Call malloc fail!");
		return -1;
	}
}
