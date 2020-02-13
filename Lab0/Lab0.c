#include <stdio.h>
#include <stdlib.h> // For exit()
#include <math.h>
#include <string.h>
#define bool int



//Unprintable ASCII chars from 0-31, 127
/* 
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    " BS", "TAB", " LF", " VT", " FF", " CR", " SO", " SI",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", " EM", "SUB", "ESC", " FS", " GS", " RS", " US",
    "space", "DEL"};  */

int DecimalConversion(char *D){
      int decimal = 0, i, remainder;
      int cn = atoi(D);
   for(i = 0; cn != 0; ++i){
      remainder = cn % 10;
      cn /= 10;
      decimal += remainder * pow(2,i);
   }
   return decimal;
}
bool getParity(unsigned int n){
   bool parity = 0;
for(;n;){
    parity = !parity;
    n = n & (n-1);
}
return parity;
}

void print(char *number){
    printf("% 8s", number);//Original
            printf("% 8c", DecimalConversion(number));//ASCII
                printf("% 8d", DecimalConversion(number));//Decimal
                    printf("% 8s", getParity(DecimalConversion(number)) ? "\todd" : "\teven");// Parity
    printf("\n");//:)
}

int main(int argc, char** argv){
      char num[100];
      char b[100000];
   printf("Enter the file's location:\n");
   scanf("%s", b);
      printf("Original   ASCII   Decimal     Parity\n");
      printf("-------------------------------------\n");
   FILE *fp = fopen(b, "r"); //reads the file

    if (fp == NULL) {
        printf("Could not find file\n"); //cant find the file or cant open file error
        exit(0);
    }
    while (fscanf(fp, "%s", & num) == 1) {//reads data from file and includes them in parameter
          char buff[9];
          int d;
        snprintf(buff, 9, "%s", num);
        d = strlen(buff);
          int i = d;
        while ( i < 8) {
            buff[i] = '0';
            i++;
        }
        print(buff);
    }
  return 0;
}
