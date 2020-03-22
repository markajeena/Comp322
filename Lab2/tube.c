#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define WRITE_END 1
#define READ_END 0

int main(int argc, char *argv[]){
	//storage vars
	pid_t cpid1, cpid2;
	int pipefd[2];
    int arg1len = 0, arg2len = 0;
	int status1, status2;
    char* buff1[100], buff2[100];

    if(argc <= 3){
        fprintf(stderr, "ERROR: USAGE: %s Not enough args\n", argv[0]);
        exit(EXIT_FAILURE);
    }else{
    //make_buffers(argv, argc, buff_1, buff_2);
    }
	if(pipe(pipefd) == -1){
		perror("pipe error");
		exit(EXIT_FAILURE);
	}

	// retrieving the args for the first command
	for(int i = 1; i < argc; i++){
		if((strcmp(argv[i], ",") == 0) || (argv[i] == NULL)){
			break;
		}
		arg1len++;
	}
	// memory allocation for list of args for first command
	char** args1 = (char**) calloc(arg1len, sizeof(char*));
	for(int i = 0; i < arg1len; i++){
		args1[i] = (char*) calloc(50, sizeof(char));
	}
	// copies first set of args into args1
	for(int i = 1; i <= arg1len; i++){
		strcpy(args1[i - 1], argv[i]);
	}

	// retrieving args for the second command
	for(int i = arg1len + 2; i < argc; i++){
		if((strcmp(argv[i], ",") == 0) || (argv[i] == NULL)){
			break;
		}
		arg2len++;
	}
	// memory allocation for the list of args for second command
	char** args2 = (char**) calloc(arg2len, sizeof(char*));
	for(int i = 0; i < arg2len; i++){
		args2[i] = (char*) calloc(50, sizeof(char));
	}
	// copies second set of args into args2
	for(int i = arg1len + 2, j = 0; i < argc; i++){
		strcpy(args2[j], argv[i]);
		j++;
	}


	cpid1 = fork();

    if(cpid1 < 0){
        fprintf(stderr, "ERROR: USAGE: %s FORK 1 FAILED\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    cpid2 = fork();

    if(cpid2 < 0){
        fprintf(stderr, "ERROR: USAGE: %s FORK 2 FAILED\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if(cpid1 > 0 && cpid2 > 0){
        //parent process prints PID of both children
        fprintf(stderr, "cpid 1 %s: $$ = %d\n", args1[0], cpid1);
        fprintf(stderr, "cpid 2 %s: $$ = %d\n", args2[0], cpid2);
		//parent closes access to the pipe
		close(pipefd[READ_END]);

		write(pipefd[WRITE_END], args1, sizeof(args1));
		write(pipefd[WRITE_END], args2, sizeof(args2));

		close(pipefd[WRITE_END]);

		waitpid(cpid1, &status1, WUNTRACED);
		waitpid(cpid2, &status2, WUNTRACED);
		//return value of 1st and 2nd cpid
	    fprintf(stderr, "cpid 1 %s: $? = %d\n", args1[0], status1);
        fprintf(stderr, "cpid 2 %s: $? = %d\n", args2[0], status2);

    }
	else if(cpid1 == 0 && cpid2 > 0){	//cpid1 process
		//take input from stdin (already done)
		//replace stdout with write part of pipe
		dup2(pipefd[READ_END], READ_END);
		//close fds
		close(pipefd[WRITE_END]);
		read(pipefd[READ_END], args1, sizeof(args1));
		close(pipefd[WRITE_END]);

		char *newargv[sizeof(args1)];

		for(size_t i = 0; i < sizeof(args1); i++){
            newargv[i] = args1[i];
		}
		execve(args1[0], newargv, NULL);
		fprintf(stderr, "ERROR: USAGE: %s EXEC 1 FAILED\n", argv[0]);
		exit(EXIT_FAILURE);

	}
		else if(cpid2 == 0 && cpid1 > 0){	//parent process
			dup2(pipefd[READ_END], READ_END);	//cpid1 process prints into the pipe, doesn't matter for race condition
			//order printed correctly to ensure no race condition issues
			close(pipefd[READ_END]);
			read(pipefd[READ_END], args2, sizeof(args2));
			close(pipefd[READ_END]);

			char *newargv[sizeof(args2)];
			for(size_t i = 0; i < sizeof(args2); i++){
                newargv[i] = args2[i];

			}

			execve(args2[0], newargv, NULL);

			fprintf(stderr, "ERROR: USAGE: %s EXEC 2 FAILED\n", argv[0]);
			exit(EXIT_FAILURE);
		}

	return 0;
}
