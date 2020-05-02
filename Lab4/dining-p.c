/*
Mark Ajina
Lab4: Rice Rice and Rice
Comp322
*/

#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <signal.h>

#define chop1  //"chopstick1"
#define chop2  //"chopstick2"
sem_t* right;
sem_t* left;

void dining(int argc, char** argv);
void eat(int num);
void think(int num);


static int end;


void eat(int num){
	fprintf(stdout, "Philosopher #%d is eating\n", num);
  usleep(rand());
}


void think(int num){
	fprintf(stdout, "Philosopher #%d is thinking\n", num);
	usleep(rand());
}


int main (int argc, char **argv) {
	dining(argc,argv);
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

int endValue(){
	end = 1;
}

int getEnd(){
	return end;
}

void signalHandler(){
	endValue();	
}

void deallocate(){
	//close right and left
	sem_close(right);
	sem_close(left);
	//unlink
	sem_unlink(chop1);
	sem_unlink(chop2);
	//deallocate both side
	sem_destroy(left);
	sem_destroy(right);
}


void dining(int argc, char** argv){
    if(argc == 3) {
        int seats = atoi(argv[1]);
        int position = atoi(argv[2]);
       	 if(seats < position) {
          	  printf("Error: not enough seats\n");
         }else{
		int cycle = 0;
		signal(SIGTERM, signalHandler);
		right = sem_open(chop1, O_CREAT,0660, 1);
		left = sem_open(chop2, O_CREAT,0660, 1);
			do{
		//wait for right & left semaphore
			sem_wait(right);
			sem_wait(left);
			eat(position);
		//show left & right are available
			sem_post(right);
			sem_post(left);
			think(position);
			cycle++;
			}while(getEnd());
		 if(getEnd() != 1){// print complete status in stderr
			  fprintf(stderr,"Philosopher #%d completed %d cycles.\n", position, cycle);
		 }

		 deallocate();
	 }
	 }else{//print error to stdout
		fprintf(stdout,"Error: please give more numbers for seats and position\n");
	 }
	 return 0;
    }
		       
