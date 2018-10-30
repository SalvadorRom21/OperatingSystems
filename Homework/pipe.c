#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
// compile with: gcc -Wall -Werror -o pipe pipe.c
int main(int ac, char*av[]){

	int pipefd[2];
	int ret;

	ret =pipe(pipefd);

	if(ret == -1)
	{
		perror("pipe");
		exit(1);

	}

	char *command1 = "./pre";
	char *command2 = "./sort";
	char *argcmd1[2];
	char *argcmd2[2];

	argcmd1[0]= "./pre";
	argcmd1[1]=NULL;

	argcmd2[0]= "./sort";
	argcmd2[1]=NULL;


	pid_t childPid = fork();
		if (childPid < 0){
			perror("fork() Error");
		exit(-1);
	}
	if (childPid != 0 ){
		wait(NULL);

		//printf("Prent pid = %d, Child pid = %d\n",
			//getpid(),childPid);
		pipefd[0]=open("output.txt",O_RDONLY);
		dup2(pipefd[0],STDIN_FILENO);
		close (pipefd[0]);
		close (pipefd[1]);
		execvp(command2,argcmd2);

	}
	else{
		//printf("Child pid= %d, Parent pid = %d\n",
		//getpid(), getppid());
	printf("Enter state initials and population (millions of people)\n" );
	printf("Press ENTER TO ENTER VALUES (STATE POPULATION) format\n");
	printf("PRESS Ctrl-D twice to stop\n");
		pipefd[1]= creat("output.txt",0777);
		dup2(pipefd[1],STDOUT_FILENO);
		close(pipefd[1]);
		close(pipefd[0]);
		execvp(command1, argcmd1);
		printf("HELLO");
	}
}