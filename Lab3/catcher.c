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
void sigHandle(int signal);

void sigHandle(int sig){
	signal(sig, sigHandle);

	printf("SIG%s caught at %ld\n", str_arr[sig - 1], time(NULL));

	counter++;
//if the signal is counter
	if(sig == terminate)
	{
		terminate++;

	}
}

int main(int argc, char** argv){
//local variables
int catcher;
  fprintf(stderr, "%s $$; %d\n"", argv[0], getpid());
 
        
          return 0;
}
