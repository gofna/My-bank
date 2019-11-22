FLAGS = -Wall -g

make:

mybanks: myBank.o 
	ar -rcs libmyBank.a myBank.o
	
mybankd: myBank.o
	gcc -shared -o libmyBank.so myBank.o

myBank.o: myBank.c myBank.h
	gcc $(FLAGS) -c myBank.c
	
mains: main.o mybanks 
	gcc $(FLAGS) -o mains main.o libmyBank.a
	
maind: main.o mybankd
	gcc $(FLAGS) -o maind main.o libmyBank.so
	
main.o: main.c myBank.h
	gcc $(FLAGS) -c main.c
	
all: mybanks mybankd mains maind

.PHONY: clean all

clean: 
	rm -f *.o *.a *.so mains maind
