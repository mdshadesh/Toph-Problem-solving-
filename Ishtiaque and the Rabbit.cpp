#include<bits/stdc++.h>
#define ll unsigned long long
#define m 1000003
using namespace std;
int main()
{
	ll t;cin>>t;
	while(t--){
		ll a,r,n,ans,tot;cin>>a>>r>>n;ans=a,tot=a;
		for(ll i=2;i<=n;i++){
			tot=(tot*r)%m;
			ans=(ans+tot)%m;
		}
		cout<<ans<<"\n";
	}
}