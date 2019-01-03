#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <sys/wait.h>
#include<Process.h>
#include "Debugger.h"

const char* str = "Hello";

void init(void)
{
	if (!access("/sdcard/Fdb/", F_OK) == 0) {
		mkdir("/sdcard/Fdb",S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}
}

int main(int argc, char* argv[])
{
	const char* name = "bin.mt.plus";
	const char* so_path = "/system/Test.so";
	init();
	int pid = Process_ReadProcess(argv[1]);
	if (pid == 0) {
		for (int i=0; i<3; i++) {
			puts("999");
			
		}
	} else {
		Debugger_Attach(pid);
		RemoteCall_SoInject(pid, so_path);
		Debugger_Start(pid, 0);
		Debugger_Detach(pid);
	}
	return 0;
}