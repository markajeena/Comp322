#Mark Ajina
#LAB2 : Launch Tube
#03/03/2020


#Executables is a Make variable that lists all the
#"executables" associated with the lab.

EXECUTABLES = launch tube
SRC1 = launch.c
file1= launch
OBJ1= launch.o

SRC2 = tube.c
file2 = tube
OBJ2 = tube.o

CC = gcc 
CFLAGS = -g

#The default target for the MAKEFILE.
all: $(EXECUTABLES)

$(EXECUTABLES):
        $(CC) $(CFLAGS) -c $(SRC1) -Wall -Wextra
        $(CC) $(CFLAGS) -o $(file1) $(OBJ1)
        
        $(CC) $(CFLAGS) -c $(SRC2) -Wall -Wextra
        $(CC) $(CFLAGS) -o $(file2) $(OBJ2)
        
#clean is used to remove all executables and objects
clean:
        rm -f $(EXECUTABLES) $(OBJ1) *~
        rm -f $(EXECUTABLES) $(OBJ2) *~
