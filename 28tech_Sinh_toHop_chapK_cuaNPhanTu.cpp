#include <bits/stdc++.h>
using namespace std;

//<Khoi tao cau hinh dau tien>
//while(<Khi chua phai cau hinh cuoi cung>){
//	<In ra cau hinh hien tai>
//	<Sinh ra cau hinh tiep theo>	
//}

int n,k,a[100],ok;

void khoitao(){
	for(int i=1; i<=k; i++){
		a[i] = i;
	}
}
void sinh(){
	int i = k;
	//n-k+i
	while( i>=1 && a[i] == n-k+i){
		--i;
	}
	if(i == 0){
		ok = 0; //day chinh la cau hinh cuoi cung
	}
	else{
		a[i]++;
		for(int j = i+1; j<=k; ++j){
			a[j] = a[j-1] + 1;
		}
	}
}

int main(){
	cin>>n;
	cin>>k;
	ok = 1;
	khoitao();
	while(ok){

		for(int i=1; i<=k;i++){
			cout<<a[i];
		}
		cout<<endl;
		sinh();
	}
}
