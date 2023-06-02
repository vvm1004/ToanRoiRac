#include <bits/stdc++.h>
int B[20];
int n = 3;

bool check(){
	for(int i=1; i<n; i++){
			if(B[i] == B[i+1] && B[i]==0 && B[i+1] == 0){
				return false;
			
		}
	}
	return true;
}
void Print(int k){
	for(int i =1; i<=k; i++){
		printf("%d \t", B[i]);
	}
	printf("\n");
	
}
void Try(int i){
	for(int j = 0; j<=1; j++){
		B[i] = j;
		if(i==n ) 
			Print(n);
		else Try(i+1);

	}
		
}
int main(){
	Try(1);
}             