#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <unistd.h>

//declare global variables
   time_t start;
   pid_t cpid;
   time_t stop;
   int status;
   struct tms start_tms, end_tms;

int main(){

   cpid = fork();
   pid_t wait;
   time(&start);
   times(&start_tms);
   printf("START: %ld\n", start);//num of sec

//check if is in child
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
	//user time, system time
   printf("USER: %ld," ,(end_tms.tms_utime - start_tms.tms_utime));
   printf(" SYS: %ld\n", (end_tms.tms_stime - start_tms.tms_stime));
	// user time of child, system time of child
   printf("CUSER: %ld,",(end_tms.tms_cutime - start_tms.tms_cutime));
   printf("CSYS: %ld\n", (end_tms.tms_cstime - start_tms.tms_cstime));

   time(&stop);
   printf("STOP: %ld\n", stop);


   return 0;
}
