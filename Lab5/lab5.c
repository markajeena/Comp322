#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  const int size = 4096;
  unsigned int pageNum, address, offset;
  
  if(argc < 2){
   printf("Error: not enough number of arguments");
    
    return EXIT_FAILURE;
  }
  
  address = atoi(argv[1]);
  
  pageNum = address/size;
  
  offset = address % size;
  
  printf("The address %d contains:\n", address);
  printf("Page Number = %d\n", pageNum);
  printf("Offset = %d\n", offset);
  
  return 0;
  
}
