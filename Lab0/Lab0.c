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
void unprintables(int number) {
    char* keys[50][6];
    keys[0][6] = "NUL"; keys[1][6] = "SOH";
    keys[2][6] = "STX"; keys[3][6] = "ETX"; 
    keys[4][6] = "EOT"; keys[5][6] = "ENQ";
    keys[6][6] = "ACK"; keys[7][6] = "BEL";
    keys[8][6] = "BS";  keys[9][6] = "TAB";
    keys[10][6] = "LF"; keys[11][6] = "VT";
    keys[12][6] = "FF"; keys[13][6] = "CR";
    keys[14][6] = "SO"; keys[15][6] = "SI";
    keys[16][6] = "DLE";keys[17][6] = "DC1";
    keys[18][6] = "DC2"; keys[19][6] = "DC3";
    keys[20][6] = "DC4"; keys[21][6] = "NAK";
    keys[22][6] = "SYN"; keys[23][6] = "ETB";
    keys[24][6] = "CAN"; keys[25][6] = "EM";
    keys[26][6] = "SUB"; keys[27][6] = "ESC";
    keys[28][6] = "FS"; keys[29][6] = "GS";
    keys[30][6] = "RS"; keys[31][6] = "US";
    keys[32][6] = "SPACE"; keys[33][6] = "DEL";

    if (number <= 32) {

        printf("% 8s", keys[number][6]);
    } else if (number >= 33 && number <= 126) {
        printf("% 8c", number);
    } else if (number == 127) {
        printf("% 8s", keys[33][6]);
    }
}


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
