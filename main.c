#include<stdio.h>
#include"myBank.h"


int main() {

char c = ' ';

while(c != 'E'){
	printf("\nTransation Type? ");
	scanf(" %c" , &c);

	switch(c){
		int x;
		int n;
		double y;
	case 'O' :
		openAccount2();
		break;
	
	case 'B' :
		printf("Account number? ");
		x = scanf("%d" , &n);
		if(x != 1 || n<900 || n>951){
			printf("invalid number");
		}
		else{
			balance(n);
		}
		break;
		
	case 'D' :
		printf("Account number? ");
		x = scanf("%d" , &n);
		if(x != 1 || n<900 || n>951){
			printf("invalid number\n");
		}
		else{
			deposite(n);
		}
		break;		
	
	case 'W' :

		printf("Account number? ");
		x = scanf("%d" , &n);
		if(x != 1 || n<900 || n>951){
			printf("invalid number\n");
		}
		else{
			withdrawal(n);
		}	
		break;
		
	case 'C' :

		printf("Account number? ");
		 x  = scanf("%d" , &n);
		if(x !=1 || n<900 || n>951){
			printf("invalid number\n");
		}
		else{
			closeAccount(n);
		}	
		break;
	
	case 'I' :
		printf("Interest rate? ");
		scanf("%lf" , &y);
		interest(y);
		break;
		
	case 'P' :
		printBank();
		break;
	
	case 'E':
		Exit();
		break;
		
	default :
		printf("error! the operator is not correct");
	}	
}
return 0;
}




