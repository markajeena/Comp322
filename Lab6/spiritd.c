#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <signal.h>
#include <syslog.h>
#include <limits.h>

pid_t pid1;
pid_t pid2;
char molePath [PATH_MAX];
int dev_null;
int log;
char homeDirectory[PATH_MAX];


void srand(unsigned int seed){
	next = seed;
}

void signalHandler(int num){
  signal(num,signalHandler);
  if(num == SIGTERM){
  //WNOHANG - specifies that waitpid should return immediately instead of waiting, 
  //if there is no child process ready to be noticed.
  int mole1 = waitpid(pid1, &mole1, WNOHANG);
  int mole2 = waitpid(pid2, &mole2, WNOHANG);
  if(mole1 == 0){
    //exit mole pid 1 
    kill(pid1, SIGKILL);
    }
  if(mole2 == 0){
    //exit mole pid 2
      kill(pid2, SIGKILL);
    }
    //exit Daemon process
  kill(getpid(), SIGKILL)
  
  }else if(num == SIGUSR1){
  int mole1 = waitpid(pid1, &mole1, WNOHANG);
    if(mole1 == 0){
      kill(pid1, SIGKILL);
    }
  }else if(num == SIGUSR2){
    int mole2 = waitpid(pid2, &mole2, WNOHANG);
   if(mole2 == 0){
    kill(pid2,SIGKILL); 
   }
  }
  
}

void moleMaker(){
  char* mole;
  
}

int main(int argc, char **argv){
  pid_t ppid;

  struct rlimit rLimitStruct;
  
  ppid = fork();
  
  if(ppid < 0 || ppid > 0){
    printf("Can't create a process")
    return EXIT_FAILURE;
    
  }else if(ppid == 0){
    umask(0);
    printf("Daemon pid : %d\n", getpid());
    setsid();
    int check = chdir("/");
    if(check == -1){
      perror("cant change directories");
      return EXIT_FAILURE;
    }
    getrlimit(RLIMIT_NOFILE, &rlimit);
        if (rlimit.rlim_max == RLIM_INFINITY)
            rlimit.rlim_max = 1024;
        for (unsigned int i = 0; i < rlimit.rlim_max; i++)
            close(i);
        dev_null = open("/dev/null", O_RDONLY);
        dup2(dev_null,0);
        dup2(dev_null,1);
        dup2(dev_null,2);
     }
  
  }  
  return 0;
  
}
