#include <bits/stdc++.h>
int B[20];
int n = 4;
int k = 3;
void Print(int k){
	for(int i = 1; i<=k; i++){
		printf("%d \t", B[i]);
	}
	printf("\n");
}
void Try(int i){
	for(int j = B[i-1] + 1; j <=n-k+i; j++){
		B[i] = j;
		if(i==k) Print(k);
		else Try(i+1);
	}
}
int main(){
	B[0] = 0;
	Try(1);
}             