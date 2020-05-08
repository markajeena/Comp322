#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv){
  FILE* filePointer;
  char lab6;
  
  fprintf(filePointer, "Pop mole%s\n", argv[0]);
  fclose(filePointer);
  return 0;
  
}
