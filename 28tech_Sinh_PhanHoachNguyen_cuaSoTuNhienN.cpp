#include <bits/stdc++.h>
using namespace std;

//<Khoi tao cau hinh dau tien>
//while(<Khi chua phai cau hinh cuoi cung>){
//	<In ra cau hinh hien tai>
//	<Sinh ra cau hinh tiep theo>	
//}

int n , a[100], cnt, ok;

void khoitao(){
	cnt = 1;
	a[1] = n;
}
void sinh(){
	int i = cnt;
	while( i>=1 && a[i] == 1){
		--i;
	}
	if(i == 0){
		ok = 0; //day chinh la cau hinh cuoi cung
	}
	else{
		a[i]--;
		int d = cnt - i + 1;
		cnt = i;
		int q = d / a[i];
		int r = d % a[i];
		if(q){
			for(int j =1; j<=q; j++){
				++cnt;
				a[cnt] = a[i];
			}
		}
		if(r){
			++cnt;
			a[cnt] = r;
		}
	}
}

int main(){
	cin>>n;
	khoitao();
	ok = 1;
	while(ok){
		for(int i=1; i<=cnt; i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		sinh();
	}
}
