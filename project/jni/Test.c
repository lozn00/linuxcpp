#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Start()
{
	char path[2][32];
	memset(path[0], 0, sizeof(path[0]));
	memset(path[1], 0, sizeof(path[1]));
	sprintf(path[0], "/sdcard/Fdb/%d.txt", getpid());
	sprintf(path[1], "/proc/%d/maps", getpid());
	FILE* fp = fopen(path[0], "wb");
	FILE* fp2 = fopen(path[1], "r");
	int c = -1;
	while ((c = fgetc(fp2)) != EOF) {
		fputc(c, fp);
	}
	fclose(fp2);
	fclose(fp);
}