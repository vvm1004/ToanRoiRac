#include <stdio.h>
int g[20][20],c[20],u=1,n;
FILE*fptr;
int Init_Graph(char*path){
	int i,j;
	fptr = fopen(path,"r");
	if(fptr==NULL){
		printf("Error");
		return 1;
	}
	fscanf(fptr,"%d",&n);
	for(i =1;i<=n;i++)
		for(j=1;j<=n;j++) g[i][j]=0;
	while(!feof(fptr)){
		fscanf(fptr,"%d",&i); fscanf(fptr,"%d",&j);
		fscanf(fptr,"%d",&g[i][j]);
		g[j][i] = g[i][j];
	}
	fclose(fptr);
	return 0;
} 

void Print(int n){
	for(int i =n;i>=1;i--)
		printf("%d\t",c[i]);
	printf("\n");
}


int Euler(int u){
	int s[20],top =1,length = 0;
	s[top] = u;
	while(top>0){
		int ok = 1;
		for(int v =1;v<=n && ok==1;v++)
			if(g[u][v]!=0){
				top += 1; s[top] = v;
				ok = 0;
				g[u][v] -= 1;
				g[v][u] = g[u][v];
				ok = 0;
			}
			if(ok==1){
				length += 1;
				c[length] = s[top]; top -= 1;
			}
			u = s[top];
	}
	return length;
}

int main(){
	Init_Graph("Euler.INP");
	int length = Euler(u);
	Print(length);
	
}