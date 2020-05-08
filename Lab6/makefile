#Mark Ajina
#05/08/2020
#Lab 6: Wack A Mole

EXECUTABLES = spiritd moles

FILE_1 = spiritd
SRC_1 = spiritd.c
OBJ_1 = spiritd.o

FILE_2 = moles
SRC_2 = moles.c
OBJ_2 = moles.o
# The CC and CFLAGS variables are defined to ensure I'm using the native compiler and
# that the correct command-line options are set

CC = gcc
CFLAGS = -g
# Here is my default target for the Makefile.  When I type make, this first target will
# be created. I.e., all the executables

all: $(EXECUTABLES)
# On the following lines (which _must_ start with a tab), are the commands I need to type -- 
# each time my source file is modified.

$(EXECUTABLES):
spiritd:
	$(CC) $(CFLAGS) -c $(SRC_1) -Wall -Wextra
	$(CC) $(CFLAGS) -o $(FILE_1) $(OBJ_1)
moles:
	$(CC) $(CFLAGS) -c $(SRC_2) -Wall -Wextra
	$(CC) $(CFLAGS) -o $(FILE_2) $(OBJ_2)


# By convention, I always have a target called
# "clean" that I used to define all temporary
# or intermediates.

clean:
	rm -f $(EXECUTABLES) $(OBJ_1) $(OBJ_2) *~
