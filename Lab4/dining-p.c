#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define SEM_FILE1  "/bensonite_chopstick_1A"
#define SEM_FILE2  "/bensonite_chopstick_2"


sem_t * returnVal;
sem_t * chopstick[3];

main () {

  returnVal = sem_open(SEM_FILE1, O_CREAT|O_EXCL, 0666, 1);
  if (returnVal == SEM_FAILED ) {
    perror(NULL);
    returnVal = sem_open(SEM_FILE1, 0);
  }

  chopstick[1] = returnVal;

  sleep(1);
  sem_close(chopstick[1]);
  sem_unlink(SEM_FILE1);
}

