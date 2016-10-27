#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	
	int count  = 0;
	
	pid_t childPid = 0;
	
	if ((childPid = fork()) == -1)
	{
		perror("fork error");
		return -1;
	}
	
	if (childPid == 0)
	{
		execv("./eightqueen",NULL);
		
		printf("child exec complete\n");
		
		exit(1);
	}
	else
	{
		printf("main thread pid:%d\n",getpid());
		sleep(3);
		int status;
		pid_t pid = wait(&status);
		printf("child status:%d,childpid:%d, orgin:%d\n",status,pid,childPid);
	}
	
	
	return 0;
}