#include <stdio.h>
#include <stdlib.h> // For exit()
#include <math.h>
#include <string.h>
#define bool int

int DecimalConversion(int D){
   int decimal = 0, i, remainder;
   for(i = 0, D != 0, ++i){
      remainder = D % 10;
      D /= 10;
      decimal += remainder * pow(2,i);
   }
   return decimal;
}

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
