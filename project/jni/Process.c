#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "Process.h"

u8 Process_ReadMemoryModuleAddr(int tid, const char* name, const char* permission)
{
	char path[32];
	u8 result = -1;
	memset(path, 0, sizeof(path));
	sprintf(path, "/proc/%d/maps", tid);
	FILE* fp = fopen(path, "r");
	if (fp == NULL) {
		return -301;
	} else {
		char buf[1024];
		memset(buf, 0, sizeof(buf));
		while(fgets(buf, sizeof(buf), fp) != NULL) {
			u8 m_start_addr = -1;
			char m_permission[16];
			char m_name[256];
			memset(m_permission, 0, sizeof(m_permission));
			memset(m_name, 0, sizeof(m_name));
			sscanf(buf, "%lX-%*lX %s %*X %*X:%*X %*d %s", &m_start_addr, m_permission, m_name);
			if (strcmp(m_name, name) == 0 && strcmp(m_permission, permission) == 0)
				result = m_start_addr;
		}
		fclose(fp);
	}
	return result;
}

int Process_ReadProcess(const char* name)
{
	int result = -1;
	DIR* dir = opendir("/proc");
	struct dirent dirent;
	struct dirent* ents = &dirent;
	memset(ents, 0, sizeof(dirent));
	if (dir != NULL) {
		while ((ents = readdir(dir)) != NULL) {
			int pid = atoi(ents->d_name);
			if (pid > 0) {
				char path[32];
				memset(path, 0, sizeof(path));
				sprintf(path, "/proc/%d/cmdline", pid);
				FILE* fp = fopen(path, "r");
				char buf[256];
				memset(buf, 0, sizeof(buf));
				fgets(buf, sizeof(buf), fp);
				if (strcmp(buf, name) == 0) {
					return pid;
				} else if (strstr(buf, name) != NULL) {
					result = pid;
				}
				fclose(fp);
			}
		}
		closedir(dir);
	}
	return result;
}
