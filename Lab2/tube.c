#include <stdio.h>
#include <unisted.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv){
pid_t cpid1, cpid2;
int check1, check2;
int pipefd[2];
  
if(pipe(pipefed) == -1){
perror("ERROR w/ Pipe);
exit(EXIT_FAILURE);
}
        
if(argc <= 1){
fprintf(stderr, "ERROR: USAGE: %s NEEDS MORE ARGS\n, argv[0]);
exit(EXIT_FAILURE);
}


cpid1 = fork();
cpid2 = fork();
}
