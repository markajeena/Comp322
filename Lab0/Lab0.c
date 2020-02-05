#include <stdio.h>
#include <stdlib.h> // For exit()
#include <math.h>
#include <string.h>
#define bool int

int DecimalConversion(char *D){
   int decimal = 0, i, remainder;
   int cn = atoi(D);// atoi Converts string into integer
   for(i = 0; cn != 0; ++i){
      remainder = cn % 10;
      cn /= 10;
      decimal += remainder * pow(2,i);
   }
   return decimal;
}
bool getParity(unsigned int n){
bool parity = 0;
while(n){
    parity = !parity;
    n = n & (n-1);
}
return parity;
}

void print(char *number){
    printf("% 8s", number);
    printf("% 8d", DecimalConversion(number));
    printf("% 8c", DecimalConversion(number));
    printf("% 8s", getParity(DecimalConversion(number)) ? "\todd\tTrue" : "\teven\tFalse");
    printf("\n");
}

int main(){
   char num[100];
   char b[100000];
   printf("Enter the file's location: \nex. C:Users:...\n");
   scanf("%s", b);
   printf("Original   ASCII   Decimal    Parity    T.ERROR\n");
   FILE *fp = fopen(b, "r"); //reads the file 

    if (fp == NULL) {
        printf("Could not find file\n"); //cant find the file or cant open file errror
        exit(0);
    }
    while (fscanf(fp, "%d", & num) == 1) { //reads data from file and includes them in parameter
        printf("%08d ", num);
            print(num);
       //something is wrong aaaaaaaaaaaaaaaaaaaaaaaaaaaaaah
   }

  return 0;


}
© 2020 GitHub, Inc.
