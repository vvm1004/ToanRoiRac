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

void DFS(int u){
	int s[20],top =1;
	s[top] = u;
	while(top>0){
		int u = s[top]; top -= 1;
		if(c[u]==1) continue;
		printf("%d\n",u);
		c[u] = 1;
		for(int v = n;v>=1;v--)
			if(g[u][v]!=0 && c[v]==0){
				top += 1; s[top] = v;
			}
	}
}

int main(){
	Init_Graph("Bai2trang41.INP");
	DFS(u);
}