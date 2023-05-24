#include <bits/stdc++.h>
using namespace std;

//<Khoi tao cau hinh dau tien>
//while(<Khi chua phai cau hinh cuoi cung>){
//	<In ra cau hinh hien tai>
//	<Sinh ra cau hinh tiep theo>	
//}

int n,k,a[100],ok;

void khoitao(){
	for(int i=1; i<=n; i++){
		a[i] = 0;
	}
}
void sinh(){
	//Bat dau tu bit cuoi cung va di tim bit 0 dau tien
	int i = n;
	while( i>=1 && a[i] == 1){
		a[i] = 0;
		--i;
	}
	if(i == 0){
		ok = 0; //day chinh la cau hinh cuoi cung
	}
	else{
		a[i] = 1;
	}
}
//bool check(){
//	int cnt = 0;
//	for(int i=1; i<=n; i++){
//		cnt += a[i];
//	}
//	return cnt == k;
//}
int main(){
	cin>>n;
//	cin>>k;
	ok = 1;
	khoitao();
	while(ok){

//		if(check()) {
//			for(int i=1; i<=n;i++){
//				cout<<a[i];
//			}
//			cout<<endl;
//		}
		for(int i=1; i<=n;i++){
			cout<<a[i];
		}
		cout<<endl;
		sinh();
	}
}
