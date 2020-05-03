#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  //define local variables
  //4kb = 4096 bytes
  const int size = 4096;
  unsigned int pageNum, address, offset;
  
  //check if # is < than 2
  if(argc < 2){
   printf("Error: not enough number of arguments");
    
    return EXIT_FAILURE;
  }//end if
  
  //Convert value into integer
  address = atoi(argv[1]);
  //computation of page number and offset
  pageNum = address/size;
  offset = address % size;
  
  //Display address, page number, and offset
  printf("The address %d contains:\n", address);
  printf("Page Number = %d\n", pageNum);
  printf("Offset = %d\n", offset);
  
  return 0;
  
}//end main
