#include <bits/stdc++.h>
using namespace std;

//<Khoi tao cau hinh dau tien>
//while(<Khi chua phai cau hinh cuoi cung>){
//	<In ra cau hinh hien tai>
//	<Sinh ra cau hinh tiep theo>	
//}

int n,a[100],ok;

void khoitao(){
	for(int i=1; i<=n; i++){
		a[i] = i;
	}
}
void sinh(){
	int i = n - 1;
	//n-k+i
	while( i>=1 && a[i] >= a[i+1]){
		--i;
	}
	if(i == 0){
		ok = 0; //day chinh la cau hinh cuoi cung
	}
	else{
		//Di tim thang > a[i] trong doan [i+1, n]
		int j = n;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		int l = i + 1, r = n;
		while(l< r){
			swap(a[l], a[r]);
			++l; --r;
		}
		//reverse(a + i + 1, a + n + 1);
		
	}
}

int main(){
	cin>>n;
	ok = 1;
	khoitao();
	while(ok){

		for(int i=1; i<=n;i++){
			cout<<a[i];
		}
		cout<<endl;
		sinh();
	}
}
