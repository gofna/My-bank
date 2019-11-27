#include<stdio.h>
#include "myBank.h"
#define COL 50
#define ROW 2
#define FIXPOS 901
#define OPEN 1
#define CLOSE 0

double bank [COL] [ROW] = {0} ;


void openAccount2() {
	double x; // the deposite
	int n;
	int indexFree = -1;
		for(int i = 0; i < COL; i++){
			if(bank[i][0] == CLOSE){
			indexFree = i; // where to put the new accout
			i = 49;
			}
		}
	if(indexFree == -1){
		printf("no enough space to open account");
	}
	else{
		printf("Initial deposite? ");
		n = scanf( "%lf", &x);
		x = 100*x; // to store the number with 2 digit after the decimal point
		x = (int)x;
		x = (double) x/100;
		if ( n != 0 ){
			bank[indexFree][0] = OPEN;
			bank[indexFree][1] = x;
			printf("your number account is :  %d \n" ,indexFree+FIXPOS);
		}
		else{
			printf("invalid number");
	}
			
   }
}

void balance(int n){
	if (bank[n-FIXPOS][0] == CLOSE){
		printf("The account is close");
	}
	else{
		double b = bank[n-FIXPOS][1];
		printf("the balance in this account is : %0.2lf \n", b);
	}
}

void deposite( int n){
	if (bank[n-FIXPOS][0] == CLOSE){
		printf("The account is close");
	}
	else{
		double m;
		printf("Amount?");
		scanf("%lf" , &m);
		m = 100*m;
		m = (int)m;
		m = (double) m/100;
		bank[n-FIXPOS][1] = bank[n-FIXPOS][1]+m;
		printf("the new balance is : %0.2lf", bank[n-FIXPOS][1]);
	}
}

void withdrawal(int n){
	if (bank[n-FIXPOS][0] == CLOSE){
		printf("The account is close");
	}
	else {
		double m;
		printf("Amount?");
		scanf("%lf", &m);
		m = 100*m;
		m = (int)m;
		m = (double) m/100;
		if(m > bank[n-FIXPOS][1]){
			printf("The operation is invalide");
		}
		else{
			bank[n-FIXPOS][1] = bank[n-FIXPOS][1] - m;
			printf("the new balance is : %0.2lf", bank[n-FIXPOS][1]);
		}
	}
}

void closeAccount(int n){
	if (bank[n-FIXPOS][0] == CLOSE){
		printf("The account is already closed");
	}
	else{
		bank[n-FIXPOS][1] = 0;
		bank[n-FIXPOS][0] = CLOSE;
	}
}

void interest(double n){
	n = n/100;
	for(int i=0 ; i<COL ; i++){
		if(bank[i][0] == 1){
			bank[i][1] = bank[i][1]+bank[i][1]*n;
			bank[i][1] = 100*bank[i][1];
			bank[i][1] = (int)bank[i][1];
			bank[i][1] = (double)bank[i][1]/100;
		}
	}
}

void printBank(){
	for(int i=0 ; i < COL ; i++){
		if(bank[i][0] == 1){
			printf("The amount in the acount %d is : " , i+FIXPOS);
			printf("%0.2lf \n", bank[i][1]);
			}
	}
}

void Exit(){
	for(int i=0 ; i < COL ; i++){
		bank[i][0] = CLOSE;
		bank[i][1] = 0;
	}
}































