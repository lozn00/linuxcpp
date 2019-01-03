#include <elf.h>
#include <stdio.h>
#include <stdarg.h>
#include <dirent.h>
#include <string.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include "Debugger.h"

/** 
 * @brief Debugger_Wait
 * @see  等待进程信号
 * @param tid            线程ID
 * @param options    选项类型
 *
 * @return 进程的状态码
 */

int Debugger_Wait(u2 tid, u4 options)
{
	int state = -1;
	waitpid(tid, &state, options);
	if (options == WNOHANG) {
		return WTERMSIG(state);
	} else if (options == WUNTRACED) {
		return WSTOPSIG(state);
	} else {
		return state;
	}
}

/** 
 * @brief Debugger_Attach
 * @see  附加进程
 * @param tid 线程ID
 *
 * @return 是否附加成功
 */


int Debugger_Attach(u2 tid)
{
	long a = ptrace(PTRACE_ATTACH, tid, NULL, NULL);
	return (a == 0) ? Debugger_Wait(tid, WUNTRACED) : (int)a;
}

/** 
 * @brief Debugger_Detach
 * @see  结束进程附加
 * @param tid 线程ID
 *
 * @return 是否成功结束附加
 */


int Debugger_Detach(u2 tid)
{
	return (int)ptrace(PTRACE_DETACH, tid, NULL, NULL);
}

/** 
 * @brief Debugger_Start
 * @see  运行程序
 * @param tid     线程ID
 * @param sig    忽略调试信号
 *
 * @return 是否成功运行
 */

int Debugger_Start(u2 tid, u4 sig)
{
	return (int)ptrace(PTRACE_CONT, tid, NULL, sig);
}

/** 
 * @brief Debugger_Stop
 * @see  暂停进程
 * @param tid   线程ID
 *
 * @return 是否暂停成功
 */

int Debugger_Stop(u2 tid)
{
	return kill(tid, SIGSTOP);
}

/** 
 * @brief Debugger_getMemory
 * @see  获取远程进程内存
 * @param tid            线程ID
 * @param addr         起始地址
 * @param src           数据源
 * @param size         数据源长度
 *
 * @return 无
 */

void Debugger_getMemory(u2 tid, u8 addr, u1* src, u4 size)
{
	int a = sizeof(u8);
	int b = size / a;
	int c = size % a;
	for (int i=0; i<b; i++) {
		void* d = (void*)(addr + (i * a));
		void* e = (void*)(src + (i * a));
		long f = ptrace(PTRACE_PEEKTEXT, tid, d, NULL);
		memcpy(e, &f, a);
	}
	if (c > 0) {
		void* d = (void*)(addr + (size - c));
		void* e = (void*)(src + (size - c));
		long f = ptrace(PTRACE_PEEKTEXT, tid, d, NULL);
		memcpy(e, &f, c);
	}
}

/** 
 * @brief Debugger_setMemory
 * @see  获取远程进程内存
 * @param tid            线程ID
 * @param addr         起始地址
 * @param src           数据源
 * @param size         数据源长度
 *
 * @return 无
 */

void Debugger_setMemory(u2 tid, u8 addr, u1* src, u4 size)
{
	int a = sizeof(u8);
	int b = size / a;
	int c = size % a;
	for (int i=0; i<b; i++) {
		void* d = (void*)(addr + (i * a));
		long* e = (long*)(src + (i * a));
		ptrace(PTRACE_POKETEXT, tid, d, *e);
	}
	if (c > 0) {
		void* d = (void*)(addr + (size - c));
		void* e = (void*)(src + (size - c));
		long f = ptrace(PTRACE_POKETEXT, tid, d, NULL);
		memcpy(&f, e, c);
		ptrace(PTRACE_POKETEXT, tid, d, f);
	}
}

/** 
 * @brief Debugger_getRegs
 * @see  获取寄存器
 * @param tid        线程ID
 * @param regs     寄存器指针
 *
 * @return 是否能成功读入
 */

int Debugger_getRegs(u2 tid, struct pt_regs* regs)
{
	memset(regs, 0, sizeof(*regs));
	
	#if defined(__arm__)
	return (int)ptrace(PTRACE_GETREGS, tid, NULL, regs);
	
	#elif defined(__aarch64__)
	
	struct iovec iov;
	memset(&iov, 0, sizeof(iov));
	iov.iov_len = sizeof(*regs);
	iov.iov_base = regs;
	return (int)ptrace(PTRACE_GETREGSET, tid, NT_PRSTATUS, &iov);
	
	#endif
}

/** 
 * @brief Debugger_setRegs
 * @see  修改寄存器
 * @param tid          线程ID
 * @param regs      寄存器指针
 *
 * @return 是否成功写出
 */

int Debugger_setRegs(u2 tid, struct pt_regs* regs)
{
	
	#if defined(__arm__)
	return (int)ptrace(PTRACE_SETREGS, tid, NULL, regs);
	
	#elif defined(__aarch64__)
	
	struct iovec iov;
	memset(&iov, 0, sizeof(iov));
	iov.iov_len = sizeof(*regs);
	iov.iov_base = regs;
	return (int)ptrace(PTRACE_SETREGSET, tid, NT_PRSTATUS, &iov);
	
	#endif
}

/** 
 * @brief Debugger_Call
 * @see   远程调用函数
 * @param tid        线程ID
 * @param addr    目标函数地址
 * @param num    远程调用函数参数个数
 * @param ...         远程进程函数可变参数
 *
 * @return 远程进程函数返回值
 */

u8 Debugger_Call(u2 tid, u8 addr, u1 num, ...)
{
	va_list v_list;
	struct pt_regs reg[2];
	va_start(v_list, num);
	Debugger_getRegs(tid, &reg[0]);
	//保存寄存器现场
	memcpy(&reg[1], &reg[0], sizeof(struct pt_regs));
	//设置LR方便返回0xB7F
	reg[1].LR = 0;
	//设置PC指向目标函数地址
	reg[1].PC = addr;
	reg[1].CPSR = 0;
	//以可变参数为媒介设置寄存器
	for (int i=0; i<num; i++)
		reg[1].regs[i] = va_arg(v_list, u8);
		//修改寄存器
	Debugger_setRegs(tid, &reg[1]);
	int state = -1;
	do {
	//重新运行等待返回0xB7F
		Debugger_Start(tid, 28);
		waitpid(tid, &state, WUNTRACED);
	} while (state != 0xb7f);
	//获取返回值
	Debugger_getRegs(tid, &reg[1]);
	//还原寄存器现场
	Debugger_setRegs(tid, &reg[0]);
	return reg[1].regs[0];
}