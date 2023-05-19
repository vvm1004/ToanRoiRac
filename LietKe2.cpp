#include<stdio.h>
#include<math.h>
int A[20],k=4,  n=5;
void Print(int k){
	for(int i=1;i<=k;i++){
		printf("%d\t",A[i]);
	}
	printf("\n");
}


int Cnk(int n,int k){
	if(k==0||k==n){
		return 1;
	}
	return Cnk(n-1,k)+Cnk(n-1,k-1);
}
void LKTH(int n,int k){
	for(int i=1;i<=k;i++)A[i]=i; Print(k);
	for(int c=1;c<Cnk(n,k);c++){
		int i=k;
		while(A[i]==n-k+i){
			i--;
		}
		A[i]=A[i]+1;
		for(int j=i+1;j<=k;j++){
			A[j] = A[j-1]+1;
		}
		Print(k);
		
	}
}
int main(){
	LKTH(n,k);
}