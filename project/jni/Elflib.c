#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Elflib.h"

#if defined(__arm__)
const char* nm_path = "/system/xbin/nm32";

#elif defined(__aarch64__)
const char* nm_path = "/system/xbin/nm64";

#endif

u8 nm_get_internal_sym_addr(const char* path, const char* name)
{
	char cmd[1024];
	u8 result = - 1;
	const char* save_path = "/sdcard/Fdb/nm.txt";
	memset(cmd, 0, sizeof(cmd));
	sprintf(cmd, "%s -D %s | grep %s >> %s",nm_path, path, name, save_path);
	system(cmd);
	FILE* fp = fopen(save_path, "r");
	if (fp == NULL) {
		return 201;
	} else {
		char buf[1024];
		memset(buf, 0, sizeof(buf));
		while (fgets(buf, sizeof(buf), fp) != NULL) {
			u8 f_addr = -1;
			char f_name[256];
			memset(f_name, 0, sizeof(f_name));
			sscanf(buf, "%lX %*c %s", &f_addr, f_name);
			if (strcmp(f_name, name) == 0)
				result = f_addr;
		}
		fclose(fp);
	}
	remove(save_path);
	return result;
}

u8 nm_get_external_sym_addr(const char* path, const char* name)
{
	char cmd[1024];
	u8 result = - 1;
	const char* save_path = "/sdcard/Fdb/nm.txt";
	memset(cmd, 0, sizeof(cmd));
	sprintf(cmd, "%s -g %s | grep %s >> %s",nm_path, path, name, save_path);
	system(cmd);
	FILE* fp = fopen(save_path, "r");
	if (fp == NULL) {
		return 201;
	} else {
		char buf[1024];
		memset(buf, 0, sizeof(buf));
		while (fgets(buf, sizeof(buf), fp) != NULL) {
			u8 f_addr = -1;
			char f_name[256];
			memset(f_name, 0, sizeof(f_name));
			sscanf(buf, "%lX %*c %s", &f_addr, f_name);
			if (strcmp(f_name, name) == 0)
				result = f_addr;
		}
		fclose(fp);
	}
	remove(save_path);
	return result;
}

u8 nm_get_all_sym_addr(const char* path, const char* name)
{
	char cmd[1024];
	u8 result = - 1;
	const char* save_path = "/sdcard/Fdb/nm.txt";
	memset(cmd, 0, sizeof(cmd));
	sprintf(cmd, "%s %s | grep %s >> %s",nm_path, path, name, save_path);
	system(cmd);
	FILE* fp = fopen(save_path, "r");
	if (fp == NULL) {
		return 201;
	} else {
		char buf[1024];
		memset(buf, 0, sizeof(buf));
		while (fgets(buf, sizeof(buf), fp) != NULL) {
			u8 f_addr = -1;
			char f_name[256];
			memset(f_name, 0, sizeof(f_name));
			sscanf(buf, "%lX %*c %s", &f_addr, f_name);
			if (strcmp(f_name, name) == 0)
				result = f_addr;
		}
		fclose(fp);
	}
	remove(save_path);
	return result;
}
