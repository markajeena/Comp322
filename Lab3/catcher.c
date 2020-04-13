#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <string.h>

//Declare global variables
static int terminateSig;
static int counter;
static char* SIGS[27] = {"HUP", "INT", "QUIT", "ILL", "TRAP",
                         "ABRT", "BUS", "FPE", "KILL", "USR1",
                         "SEGV", "USR2", "PIPE", "ALRM", "TERM", 
                         "STKFLT", "CHLD", "CONT", "STOP", "TSTP",
                         "TTIN", "TTOUT", "URG", "XCPU", "XFSZ",
                         "VTALRM", "PROF", "WINCH"};


int main(int argc, char** argv){
//local variables
int catcher;
  fprintf(stderr, "%s $$; %d\n"", argv[0], getpid());
 
        
          return 0;
}
