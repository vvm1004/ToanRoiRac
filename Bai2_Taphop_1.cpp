#include<stdio.h>
#include<stdlib.h>
#define Max 50
//----------------------------------------//
int A[Max],n,B[Max],m;
//---------------------------------------//
int Init(int M[],int &k,char *path){
	FILE *fptr;
	if(!(fptr=fopen(path,"r"))){
		system("Error");
		return 0;
	}
	k=0;
	while(!feof(fptr)){
		fscanf(fptr,"%d",&M[k]);
		k++;
	}
	fclose(fptr);
	return 1;
}
//----------------------------------------//
int Coppy(int A_Temp[],int &n_Temp,int A[],int n){
	for(int i=0;i<n;i++)	A_Temp[i]=A[i];
	n_Temp=n;
	return 0;
}
//----------------------------------------//
void Delete(int M[],int &n){
	int i,j,k;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++)
			if(M[i]==M[j]){
				for(k=j;k<n-1;k++)	M[k]=M[k+1];
				n=n-1;
				j=j-1;
			}
	}
}
//-----------------------------------------//
void Sort(int M[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)
			if(M[j]<M[i]){
				int temp=M[i];
				M[i]=M[j];
				M[j]=temp;
			}
	}
}
//----------------------------------------//
void Print(int M[], int n){
	for(int i=0; i<n; i++){
		printf("%3d", M[i]);
	}
	printf("\n");

}
//----------------------------------------//
int Equal (int A[], int B[], int k){
	int Ok =1;
	for(int i=0; i<k; i++){
		if(A[i] != B[i]){
			Ok = 0;
			break;
			
		}
	}
	return Ok;
	
}
//----------------------------------------//
int main(int argc, char** argv){
	if(Init(A, n, (char*) "Set_A.INP") && Init(B,m,(char*) "Set_B.INP")){
		int A_Temp[Max], n_temp, B_Temp[Max], m_temp;
		Coppy(A_Temp, n_temp, A, n);
		Coppy(B_Temp, m_temp, B, m);
		Delete(A_Temp, n_temp);
		Delete(B_Temp, m_temp);
		if(m_temp == n_temp){
			Sort(A_Temp,n_temp);
			Sort(B_Temp,m_temp);
			if(Equal(A_Temp, B_Temp, n_temp) == 1)
				printf("Hai tap hop bang nhau \n");
			else
				printf("Hai tap hop khong bang nhau \n");
		}
		else{
			printf("Hai tap hop khong bang nhau \n");
		
		}
		printf("A=");
		Print(A,n);
		printf("\nB=");
		Print(B,m);

	}
	return 0;
}

