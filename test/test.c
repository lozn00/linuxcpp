#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//gcc test.c -o test&&./test
void executeCMD()
{
	const char *cmd = "cat a.txt";
    char buf_ps[1024] = {0};
    FILE *ptr;
    if((ptr = popen(cmd, "r"))!=NULL)
    {
    	printf("cmd = %s, ptr = %p", cmd, ptr);
        fgets(buf_ps, sizeof(buf_ps), ptr);
        {
           printf("buf_ps len = %d, %s",( int)strlen(buf_ps), buf_ps);
        }
        pclose(ptr);
        ptr = NULL;
    }
    else{
        printf("popen %s error\n", cmd);
        }
}

int main(){
 executeCMD();
return 0;
}
