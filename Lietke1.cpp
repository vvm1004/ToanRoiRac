#include <stdio.h>
#include <math.h>
int B[20], k=3, n=5;
void Print(int k){
	for(int i=1; i<=k; i++)
		printf("%d\t", B[i]);
	printf("\n");
}
void XoaNP(int k){
	for(int i=1; i<=k ; i++) B[i] = 0;
	Print(k);
	for(int c =1; c < pow(2,k); c++){
		int i =k;
		while(B[i] == 1) i = i-1;
		B[i] = B[i] + 1;
		for(int j = i+1; j<=k; j++) B[j] = 0;
		Print(k);
	}
}
void HVLap(int n, int k){
	for(int i=1; i<=k ; i++) B[i] = 1;
	Print(k);
	for(int c =1; c < pow(n,k); c++){
		int i =k;
		while(B[i] == n) i = i-1;
		B[i] = B[i] + 1;
		for(int j = i+1; j<=k; j++) B[j] = 1;
		Print(k);
	}
}
int main(){
//	HoanViLap(k);
	HVLap(n,k);
}
