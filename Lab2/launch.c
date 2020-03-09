/*Mark Ajina
Start date - 03/03/2020 
End date - 
Lab 2 - Launch Tube */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv){
      int curr;
     pid_t cpid = fork();
      
      if(argc <= 1){
       exit(EXIT_FAILURE);     
      }
      
if(cpid == 0){
      
      printf("PPID: %d, ", getppid());//parent process ID
         printf("PID: %d\n", getpid());//childs process ID
   return 0;
      
   }else if(cpid > 0){ //checks if in parent
      waitpid(cpid, &curr, WUNTRACED);
   //times(&end_tms);

   }

   //if fork fails
   else {
      printf("FORK FAILED");
      return 0;
   }
}
