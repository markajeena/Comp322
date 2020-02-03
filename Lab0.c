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

int main(){
int num;
   char b[255];
   printf("Enter the files location: \nex. C:\Users\...");
   scanf("%s", b);
   printf("Original   ASCII   Decimal    Parity    T.ERROR\n");
   FILE *fp = fopen(b, "r"); //reads the file 

    if (fp == NULL) {
        printf("Could not find file\n"); //cant find the file or cant open file errror
        exit(0);
    }
    while (fscanf(fp, "%d", & num) == 1) { //reads data from file and includes them in parameter
        printf("%08d ", num);
            printf(num);
   }

  return 0;


}
