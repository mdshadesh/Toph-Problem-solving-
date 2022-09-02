#include<bits/stdc++.h>
using namespace std;
const int mx=1e7+5;
int f[mx],ks,pr[664579];
int main()
{
	for(int i=4;i<mx;i+=2)
        f[i]=1;
	for(int i=3;i*i<mx;i+=2)
        if(!f[i])
		   for(int j=i*i;j<mx;j+=i+i)
                f[j]=1;
	for(int i=2;i<mx;i++)
        if(!f[i])
           pr[ks++]=i;
	int t; cin>>t; 
    while(t--)
    {
		long long n,c1=1; cin>>n; n*=2;
		for(auto i:pr)
        {
			long long c=1; 
            while(n%i==0)
                 n/=i,c++; c1*=c;
		} 
        if(n!=1)
            c1*=2;
		cout<<(c1+1)/2<<endl;
	}
	return 0;
}