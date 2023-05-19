#include<stdio.h>
#include<math.h>
int A[20],  n=4;
void Print(int k){
	for(int i=1;i<=k;i++){
		printf("%d\t",A[i]);
	}
	printf("\n");
}
int gt(int n){
	if(n==0) return 1;
	return n*gt(n-1);
}
void LKHV(int n){
	for(int i=1;i<=n;i++){
		A[i]=i;
	}
	Print(n);
	for(int c=1;c<gt(n);c++){
		int j=n-1;
		while(A[j]>A[j+1])j-=1;
		int i=n;
		while(A[i]<A[j])i-=1;
		int temp=A[i];
		A[i]=A[j];
		A[j]=temp;
		j+=1;
		i=n;
		while(j<i){
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			i-=1;
			j+=1;
		}
		Print(n);
	}
}
int main(){
	LKHV(n);
}