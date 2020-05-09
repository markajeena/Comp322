#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char **argv){
  //init file pointer and home directory with maximum pathing
  FILE* filePointer;
  char homeDirect[PATH_MAX];
  
  // "/home/markajeena/lab6.log
  chdir("/");
  strcat(homeDirect, getenv("HOME"));
	strcat(homeDirect, "/lab6.log");
	printf("path to home directory: %s\n", homeDirect);
  
  //prints in file
	filePointer = fopen(homeDirect, "a");
  fprintf(filePointer, "Pop mole%s\n", argv[0]);
  fclose(filePointer);//close file

  int i = 1;
  while(i = 1){
   //waits for termination 
  }
  
  return EXIT_SUCCESS;
}
