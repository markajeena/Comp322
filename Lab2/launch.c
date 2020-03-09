/*Mark Ajina
Start date - 03/03/2020 
End date - 
Lab 2 - Launch Tube */

#include <stdio.h>

int main(){
if(cpid == 0){
      printf("PPID: %d, ", getppid());//parent process ID
         printf("PID: %d\n", getpid());//childs process ID
   return 0;
   }else if(cpid > 0){ //checks if in parent
   wait = waitpid(cpid, &status, WUNTRACED);//waits for child to finish

   printf("PPID: %d, PID: %d, CPID: %d, RETVAL: %d\n", getppid(), getpid(), wait, status);

   times(&end_tms);

   }

   //if fork fails
   else {
      printf("FORK FAILED");
      return 0;
   }
}
