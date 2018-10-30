#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char* argv[]){

	//printf("the number of arg are %d",argc);
	//printf("%s",argv[3]);
	//int i=0;
	//int cnt=0;
	//char* arg[argc];
	//for(int i=0;i<argc-1;i++)
	//{
	//arg[i]= argv[i+1];
	//cnt++;
	//}
	//arg[argc-1]=NULL;


	pid_t childPid=fork();
	if (childPid < 0){
		perror("fork() Errordfakljfl");
		exit(-1);
	}

	if (childPid != 0 ){
		wait(NULL);

		printf("Prent pid = %d, Child pid = %d\n",
			getpid(),childPid);

	} 
	else{
		printf("Child pid= %d, Parent pid = %d\n",
		getpid(), getppid());

		int i=0;
		int cnt=0;
		char* arg[argc];
		for(int i=0;i<argc-1;i++)
		{
		arg[i]= argv[i+1];
		cnt++;
		}
		arg[argc-1]=NULL;

		execvp(arg[0],arg);
		{
			perror("exec");
		} 
	}
}
