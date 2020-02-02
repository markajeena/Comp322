#include <stdio.h>
#include <stdlib.h> // For exit()
void readFile(){
FILE *fp;
   char filename[100], c;
   printf("Enter the filename to open \n");
   scanf("%s", filename);

   fp = fopen(filename, "r");
   if(fp == NULL){
         printf("Cant open file \n");
            exit(0);

      }
   c = fgetc(fp);
   while(c != EOF){
    printf("%c",c);
    c = fgetc(fp);
   }
    fclose(fp);

}

int main(){
readFile();


}
