#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int A[20], n, B[20], m, C[20], k;
int Init(int M[], int &k, char *path){
	FILE *fptr;
	if((fptr = fopen(path, "r"))== NULL){
		system("Error"); return 1;
	}
	k=0;
	while(!feof(fptr)){
		fscanf(fptr, "%d", &M[k]);
		k++;
	}
	fclose(fptr);
	return 0;
}


void Delete(int M[], int &n){
	int i, j, k;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(M[i]==M[j]){
				for(k=j;k<n-1;k++){
					M[k]=M[k+1];
					
				}
				n=n-1; j=j-1;
			}
		}
	}
}

void Print(int M[], int &n){
	for(int i=0;i<n;i++){
		printf("%3d", M[i]);
	}
	printf("\n");
}

void sub_union(int A[],int n,int B[],int m, int C[], int &k){
	int i,j;
	k = 0;
	i = 0;
	while(i < n){
		int ok = 1;
		for(j =0; j<m && ok; j++)
			if(B[j] == A[i]) ok =0;
			if(ok){
				C[k] = A[i];
				k++;
			}
		i++;
	}
	
}

int main(int argc, char** argv){
	if(Init(A,n,(char*)"Set_A.INP")==0 && Init(B,m,(char*)"Set_B.INP")==0){
		cout<<"A:  "; Print(A,n); cout<<endl;
		cout<<"B:  "; Print(B,n); cout<<endl;
		Delete(A,n); Delete(B,m);
		sub_union(A,n,B,m,C,k);
		cout<<"C:  "; Print(C,k); cout<<endl;
	}
	return 0;
}



























