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
pid_t dpid; //Daemon

int main(int argc, char **argv){
  pid_t ppid;
  umask(0);
  ppid = fork();
  int dev_null;
  
  if(ppid < 0 || ppid > 0){
    printf("Can't create a process")
    return EXIT_FAILURE;
    
  }else if(ppid == 0){
    setsid();
    int check = chdir("/");
    if(check == -1){
      perror("cant change directories");
      return EXIT_FAILURE;
    
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
