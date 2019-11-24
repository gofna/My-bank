#include<stdio.h>
#include "myBank.h"

double bank [50] [2] = {0} ;


void openAccount2() {
	double x;
	int n;
	int indexFree = -1;
		for(int i = 0; i < 50; i++){
			if(bank[i][0] == 0){
			indexFree = i;
			i = 49;
			}
		}
	if(indexFree == -1){
		printf("no enough space to open account");
	}
	else{
		printf("Initial deposite? ");
		n = scanf( "%lf", &x);
		x = (int)100*x;
		x = (double) x/100;
		if ( n != 0 ){
			bank[indexFree][0] = 1;
			bank[indexFree][1] = x;
			printf("your number account is :  %d \n" ,indexFree+901);
		}
		else{
			printf("invalid number");
	}
			
   }
}

void balance(int n){
	if (bank[n-901][0] == 0){
		printf("The account is close");
	}
	else{
		double b = bank[n-901][1];
		printf("the balance in this account is : %0.2lf \n", b);
	}
}

void deposite( int n){
	if (bank[n-901][0] == 0){
		printf("The account is close");
	}
	else{
		double m;
		printf("Amount?");
		scanf("%lf" , &m);
		m = (int)100*m;
		m = (double) m/100;
		bank[n-901][1] = bank[n-901][1]+m;
		printf("the new balance is : %0.2lf", bank[n-901][1]);
	}
}

void withdrawal(int n){
	if (bank[n-901][0] == 0){
		printf("The account is close");
	}
	else {
		double m;
		printf("Amount?");
		scanf("%lf", &m);
		m = (int)100*m;
		m = (double) m/100;
		if(m > bank[n-901][1]){
			printf("The operation is invalide");
		}
		else{
			bank[n-901][1] = bank[n-901][1] - m;
			printf("the new balance is : %0.2lf", bank[n-901][1]);
		}
	}
}

void closeAccount(int n){
	if (bank[n-901][0] == 0){
		printf("The account is already closed");
	}
	else{
		bank[n-901][1] = 0;
		bank[n-901][0] = 0;
	}
}

void interest(double n){
	n = n/100;
	for(int i=0 ; i<50 ; i++){
		if(bank[i][0] == 1){
			bank[i][1] = bank[i][1]+bank[i][1]*n;
		}
	}
}

void printBank(){
	for(int i=0 ; i < 50 ; i++){
		if(bank[i][0] == 1){
			printf("The amount in the acount %d is : " , i+901);
			printf("%0.2lf \n", bank[i][1]);
			}
	}
}

void Exit(){
	for(int i=0 ; i < 50 ; i++){
		bank[i][0] = 0;
		bank[i][1] = 0;
	}
}































