#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int A[10], n, B[10], m, C[10], k;
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
		cout<<M[i]<<"  ";
	}
}

void union_set(int A[],int n,int B[],int m, int C[], int &k){
	int i,j;
	for(i=0; i<n;i++){
		C[i]=A[i];
		k++;
	}
	i=0;
	while(i<m){
		int ok=1;
		for(j=0;j<k;j++)
			if(C[j]==B[i]){
				ok=0; break;
			}
		
		if(ok==1){
			C[k]=B[i];
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
		union_set(A,n,B,m,C,k);
		cout<<"C:  "; Print(C,k); cout<<endl;
	}
	return 0;
}



























