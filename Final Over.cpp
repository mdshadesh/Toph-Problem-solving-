#include<iostream>
using namespace std;

int main()
{
	int r;
	cin>>r;
	for(int i=0;i<11;++i) {
		int p,x;
		cin>>p>>x;
		if (bool(10-p)&r*p>x) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}