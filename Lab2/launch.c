/*Mark Ajina
Start date - 03/03/2020 
End date - 
Lab 2 - Launch Tube */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv){
      int curr;
     pid_t cpid;
      char* flocate;
      
      flocate = argv[1];
      
      char **args = (char** ) calloc(argc-1, sizeof(char*));
      
      for(int i = 0; i < argc - 1; i++){
            args[i] = (char*) calloc(50, sizeof(char));
      }
      
      if(argc < 2){
            for(int i = 1; i < argc; i++)
                  strcpy(argv[i-1], argv[i]);
      }
      cpid = fork();
      
      if(argc <= 1){
            fprintf(stderr, "ERROR: USAGE: %s NEEDS MORE ARGS\n", argv[0]);
       exit(EXIT_FAILURE);     
            
      }
      
if(cpid == 0){
      if(argc < 2){
            printf("ERROR, Please input filename\n");
            
      }
      else{
            execve(flocate, args,null);
      }
}
      
   }else if(cpid > 0){ //checks if in parent
      fprintf(stderr, "CPID: %d\n", getpid());
      waitpid(cpid, &curr, 0);
      fprintf(stderr, "RETEVAL: %d\n", curr);
      for(int i = 0; i < argc; i++){
                  free(args[i]);
      }
      free(args);
   }

   //if fork fails
   else {
      printf("FORK FAILED");
      return 0;
   }
}
