#include <bits/stdc++.h>
using namespace std;

//<Khoi tao cau hinh dau tien>
//while(<Khi chua phai cau hinh cuoi cung>){
//	<In ra cau hinh hien tai>
//	<Sinh ra cau hinh tiep theo>	
//}

//next_permutation(a, a+n)
//prev_permutation(a, a+n)
int main(){
	int n;
	cin>>n;
	int a[n];
//	for(int i=0; i<n; i++) a[i] = i +1;
	for(int i=0; i<n; i++) a[i] = n - i;

	do{
		for(int i=0; i<n; i++){
			cout<<a[i];
		}	
		cout<<endl;
	}while(prev_permutation(a, a+n));
	
//	string s = "abcdef";
//	next_permutation(s.begin(), s.end());
//	cout<<s<<endl;
	return 0;
}
