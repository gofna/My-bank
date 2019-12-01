#ifndef  _MYBANK_H_
#define _MYBANK_H_
#define ACCOUNTS 50
#define STATUS 2

extern double bank [ACCOUNTS] [STATUS] ;

void openAccount2();
void balance(int n);
void deposite( int n);
void withdrawal(int n);
void closeAccount(int n);
void printBank();
void interest( double n);
void Exit();

#endif