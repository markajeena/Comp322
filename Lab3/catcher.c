#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <string.h>

//Declare global variables
static int terminate = 0;
static int counter = 0;
static char* SIGS[27] = {"HUP", "INT", "QUIT", "ILL", "TRAP",
                         "ABRT", "BUS", "FPE", "KILL", "USR1",
                         "SEGV", "USR2", "PIPE", "ALRM", "TERM", 
                         "STKFLT", "CHLD", "CONT", "STOP", "TSTP",
                         "TTIN", "TTOUT", "URG", "XCPU", "XFSZ",
                         "VTALRM", "PROF", "WINCH"};

void sigCatch(int n) {
//this method checks if the number is the same as USR1 and/or 2
//then prints out what time it has been caught and signal
    time_t sec;
    time(&sec);

    if(n == 15) {
        terminate++;
    }else{
        terminate = 0;
    }
	
    if(n == SIGUSR1) {
        fprintf(stdout, "SIGUSR1 caught at %ld\n", sec);
	    
    } else if(n == SIGUSR2) {
        fprintf(stdout, "SIGUSR2 caught at %ld\n", sec);
	    
    }else {
        
        fprintf(stdout, "SIG%s caught at %ld\n", SIGS[n-1], sec);
    }
    counter++;
}

void sigHandle(int sig){
    for(int i = 1; i < argc; i++) {
        for(int j = 0; j < 27; j++) {
  
            if(strcmp(argv[i], "USR1")) {
            }
		
            if(strcmp(argv[i], "USR2")) {
		
	    }else {

            }
        }
    }
//if the signal is counter
	while(terminate < 3){
		pause();
	}
	fprintf(stderr, "catcher: Total signals count = %d\n", counter);
}

int main(int argc, char** argv){
//local variables
int catcher;
  fprintf(stderr, "%s $$; %d\n"", argv[0], getpid());
 
        
          return 0;
}
