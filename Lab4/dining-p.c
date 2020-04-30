/*
Mark Ajina
Lab4: Rice Rice and Rice
Comp322

*/

#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


#define chop1  //"chopstick1"
#define chop2  //"chopstick2"
sem_t* right;
sem_t* left;

int end;

void eat(int num){
	fprintf(stdout, "Philosopher #%d is eating\n", num);
  usleep(rand());
}


void think(int num){
	fprintf(stdout, "Philosopher #%d is eating\n", phil);
	usleep(rand());
}


int main (int argc, char **argv) {
	int cycles = 0;
	int position = atoi(argv[2]);
	int seats = atoi(argv[1]);
   if(position > seats){
	printf("Error: not enough seats\n");	   
   }
  /*returnVal = sem_open(SEM_FILE1, O_CREAT|O_EXCL, 0666, 1);
  if (returnVal == SEM_FAILED ) {
    perror(NULL);
    returnVal = sem_open(SEM_FILE1, 0);
  }

  chopstick[1] = returnVal;

  sleep(1);
  sem_unlink(SEM_FILE1);
  */
}

void signalHandler(int num){
	printf("SIGTERM(%d) processed\n", num);
 //sem_close(chop1); 
 //sem_unlink(right); 
}

void dine(int argc, char** argv){

}
