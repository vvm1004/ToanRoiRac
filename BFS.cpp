#include <bits/stdc++.h>
int G[20][20]; 
int n; 
int C[20]; 
FILE *fptr;
//----------------------------------------------------------------
int Init_Graph(char *path){
	int i,j;
	fptr = fopen(path, "r");
	if(fptr==NULL){
		system("Error");
		return 1;
	}
	fscanf(fptr, "%d", &n);
	for(i = 1; i<=n; i++)
		for(j = 1; j<=n; j++) G[i][j] = 0;
	while(!feof(fptr)){
		fscanf(fptr, "%d", &i); fscanf(fptr, "%d", &j);
		fscanf(fptr, "%d", &G[i][j]);
		G[j][i] = G[i][j];
	}
	fclose(fptr);
	return 0;
}
//----------------------------------------------------------------
void BFS(int u){
	int Q[20];
	int first = 1;
	int last = 1;
	Q[last] = u;
	C[u] = 1;
	while(first <= last){
		int u = Q[first];
		first = first + 1;
		printf("%d \t", u);
		for(int v = 1; v<=n; v++)
			if(G[u][v] != 0 && C[v] == 0){
				last = last + 1;
				Q[last] = v;
				C[v] = 1;
			}
	}
	
}
int main(){
//	int i;
//	if(!Init_Graph("Graph1.INP")) View_Graph(G,n);
	Init_Graph("BFS.INP");
	int u = 1;
	BFS(u);
	return 0;
}
