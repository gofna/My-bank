FLAGS = -Wall -g

make:

mybanks: myBank.o 
	ar -rcs libmyBank.a myBank.o
	
myBank.o: myBank.c myBank.h
	gcc $(FLAGS) -c myBank.c
	
mains: main.o mybanks 
	gcc $(FLAGS) -o mains main.o libmyBank.a
	
main.o: main.c myBank.h
	gcc $(FLAGS) -c main.c
	
all: mybanks mains

.PHONY: clean all

clean: 
	rm -f *.o *.a  mains
