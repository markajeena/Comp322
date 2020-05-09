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
//char molePath [PATH_MAX];
int dev_null;
char* moleDirectory;


void signalHandler(int num){
//reregister signal
  signal(num,signalHandler);
int mole1, mole2;
//sig equal terminate then kills both moles
  if(num == SIGTERM){
  //WNOHANG - specifies that waitpid should return immediately instead of waiting, 
  //if there is no child process ready to be noticed.
  	mole1 = waitpid(pid1, &mole1, WNOHANG);
  	mole2 = waitpid(pid2, &mole2, WNOHANG);
  	if(mole1 == 0){
   	 //exit mole pid 1 
    	kill(pid1, SIGKILL);
   	 }
	  if(mole2 == 0){
   	 //exit mole pid 2
     	 kill(pid2, SIGKILL);
   	 }
   	 //exit Daemon process
  	kill(getpid(), SIGKILL);
  
   //if signal = usr1 then init mole1 only
  }else if(num == SIGUSR1){
  mole1 = waitpid(pid1, &mole1, WNOHANG);
  mole2 = waitpid(pid2, &mole2, WNOHANG);
   	//if mole1 = has no processes then kill	  
   	 if(mole1 == 0){
     	 kill(pid1, SIGKILL);
    	}
	  else if(mole2 == 0){
	 return;
	}
	  moleMaker();
   //if sig = usr2 then init mole2 only	  
  }else if(num == SIGUSR2){
   mole2 = waitpid(pid2, &mole2, WNOHANG);
   mole1 = waitpid(pid1, &mole1, WNOHANG);
	//if mole2 = no processes then kill
   	if(mole2 == 0){
    	kill(pid2,SIGKILL); 
	   
   	}else if(mole2 == 0)
	  return;
  }
  	moleMaker();
}

void moleMaker(){
	  char* mole;
	  srand(time(0));//less likely to get the same random number
	  int rando = (rand()%2);
	char args[3];
	if(rando == 1){
		//fork pid1 and set mole to 1
		pid1 = fork();	
		mole = "1";
		args[0] = moleDirectory;
		args[1] = mole;
		args[2] = NULL;
		execv(args[0], args);
	}else {
		//fork pid2 and set mole to 2
		pid2 = fork();
		mole = "2";
		args[0] = moleDirectory;
		args[1] = mole;
		args[2] = NULL;
		execv(args[0], args);
	}
	
}

int main(int argc, char **argv){
  pid_t ppid;
  char homeD;
  struct rlimit rLimitStruct;
  ppid = fork();
  
  if(ppid > 0){
    printf("Can't create a process\n");
    return EXIT_FAILURE;
    
  }else if(ppid == 0){
    umask(0);
    //catch signals
    signal(SIGUSR1, signalHandler);
    signal(SIGUSR2, signalHandler);
    signal(SIGTERM, signalHandler);
    //
	char buff[4096];
    moleDirectory = getcwd(buff, 4096);
    strcat(moleDirectory, "/mole");
    printf("Daemon pid : %d\n", getpid());
    setsid();
    int check = chdir("/");
    strcat(homeD, getenv("HOME"));
    strcat(homeD, "/lab6.log");
    int log = open(homeD, O_CREAT, 0770);
    if(log == -1){
      perror("cant change directories\n");
      return EXIT_FAILURE;
    }
    getrlimit(RLIMIT_NOFILE, &rLimitStruct);
        if(rLimitStruct.rlim_max == RLIM_INFINITY)
            rLimitStruct.rlim_max = 1024;
        for (unsigned int i = 0; i < rLimitStruct.rlim_max; i++)
            close(i);
        dev_null = open("/dev/null", O_RDONLY);
        dup2(dev_null,0);
        dup2(dev_null,1);
        dup2(dev_null,2);
	  while(1){
	  //waits for termination
	  pause();
	  }
	  
     }
	  
  
  return 0;
  
}
