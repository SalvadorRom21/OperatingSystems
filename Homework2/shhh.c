/*			Lab 2 Partial Example			*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


int main()

{

char *path, *argv[20], buf[80], n, *p;

int m, status, inword, continu;


//Starts in a while loop so that after each commnad in the shell is executed
//it will repeadt again. unless exit commnand is given.
while(1) {



inword = 0;//false

p = buf;

m = 0;

continu=0;//flase



printf( "\nshhh> ");

//get a single input from the command line input and if
//it does not  end line or if conintue is true.
while ( ( n = getchar() ) != '\n'  || continu ) { 

	//printf("Charatcter is :%c", n);
	if ( n ==  ' ' ) { 

	    if ( inword ) {

		inword = 0;

		*p++ = 0;

	    } 

	}

	else if ( n == '\n' ) continu = 0;
	//if it is not \\ AND !inword contunue = true
	else if ( n == '\\' && !inword ) continu = 1;

	else {

	    if ( !inword ) {

		 inword = 1;
		 //printf("m value: %d" ,m);

		 argv[m++] = p;

		 *p++ = n;

	     }

	     else 

		 *p++ = n;

	}

}	

*p++ = 0;
//sets the last element as the null
argv[m] = NULL;
//printf("FINAL VALUE OF M: %d ", m);

int s1 = sizeof(argv);
int s2 = sizeof(argv[0]);
int arrLen = s1/s2;

//printf("s1 %d",s1);
//printf("s2 %d", s2);

int numbElements = m ;
int i;

bool inputR = false;
bool outputR = false;
int pipeCount = 0;
int comCount = 0; 
char *inputFile[1];
char *outputFile[1];

for(i=0;i<numbElements;i++){
	if(strcmp(argv[i],"<") == 0){
		inputR = true;
		printf("Hello input redirection\n");
		argv[i] = 0;
		inputFile[0]=argv[1+i];
		argv[1+i]=0;
		i++;
		printf("Input File : %s \n",inputFile[0]);
	}
	else if(strcmp(argv[i], ">")==0){
		outputR = true;
		printf("Hello output redirection\n");
		argv[i] = 0;
		outputFile[0] = argv[1+i];
		argv[1+i]=0;
		i++;
		printf("Output File: %s \n", outputFile[0]);
	}
	else if(strcmp(argv[i],"|")==0){
		pipeCount = pipeCount + 1;
		argv[i] = 0; 
	}
	//printf("number of elements in the array: %s", *(argv + i));
}



printf("numbers of pipes: %d", pipeCount);



//printf("The number of commands in the array are %d", comCount);



//int c;

/*for(c=0; c <comCount; c++)
{
	printf("Command %d is : %s \n", comCount, *(commands + c));
}
//This exits the program if the user types exit
*/
if ( strcmp(argv[0],"exit") == 0 ) exit (0);
//if ( strcmp(commands[0],"exit") == 0 ) exit (0);
 	
 int rp[2];
 int lp[2];
 
 pid_t pid;


 if(pipe(rp) < 0){
 	fprintf(stderr, "Error creating pipe.\n");
 	exit(0);
 }

//char *commands[10];
	//commands[0]= argv[0];
	//commands[1]= argv[1];


printf("HELLO WORLD");

pid_t childPid = fork();

printf("ChildPID %d", childPid);
	if(childPid < 0){
		perror("fork() Error");
	exit(-1);
	}

	if(childPid != 0){
		wait(NULL);
		//dup2(rp[0],0);
		//close(rp[0]);
		//close(rp[1]);
		//execvp(argv[0], argv);
	}
	else{
		//dup2(rp[1],1);
		//close(rp[0]);
		//close(rp[1]);
		execvp(argv[0],argv);
	}

}
}



//rp[0] will be the read end of the pipe.
//rp[1]  will be the write end of the pipe
/*

steps to figure it out:

	analyze the characters that have been inputed by the user in each command
	if there is a '<' character. replace it with a 0
		then set input state to true
	if there is a '>' character then set the output state to true and set it to 0
	keep track of all of the '|' characters becasue that those are the number of pipes se
	that will be created by the program.

Once we have the character string analzed then we have the ability to execute everything we need 
	creat a child process depending on all of the amount of pipes we need. pipe + 1 
		if the program has a input text then set the first process to take 
		in the input from the file instead of standard input.
	if there is a pipe between two processes make sure to changet he fd table to reflect that
Things to think about
	should i make pipes depending on the number that there are. (maybe make pipe array)

Pipe ideas:
	-figure out simple (command)| (command)

*/
	

