#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int n=3;
char A='A', B='B',C='C';
int dem = 0;

void chuyen(int n, char A, char B, char C){
	if(n>1){
		chuyen(n-1,A,C,B);
		chuyen(1,A,B,C);
		chuyen(n-1,B,A,C);
	}
	else{
		cout<<A<<"->"<<C<<endl;
		dem++;
	}
}
int main(int argc, char** argv){
	chuyen(20,A,B,C);
	cout<<"So len chuyen "  << dem;
	return 0;
}