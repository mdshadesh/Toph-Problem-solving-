#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll f1=0,f2=1,f3=0,r1,r2;
	bool k=0;
	cin>>r1>>r2;
	if(r1==0)cout<<0<<endl;
	if(r1<2){cout<<1<<endl;bool k=1;}
	for(int i=0;i<=r2;i++){
		f1=f2;
		f2=f3;
		f3=f1+f2;
		if(f3>=r1 && f3<=r2 && f3>1)cout<<f3<<endl;
	}
	
	return 0;

}