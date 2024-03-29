CC = gcc
AR = ar -rcs
OBJECTS_MAIN = main.o
OBJECTS_LIB = myBank.o
FLAGS = -Wall


all: mybanks mains

mains: main.o mybanks 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a
	
mybanks: libmyBank.a

libmyBank.a: $(OBJECTS_LIB) myBank.h
	$(AR) libmyBank.a $(OBJECTS_LIB)
	
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
	
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

.PHONY: clean all mybanks

clean: 
	rm -f *.o *.a  mains
