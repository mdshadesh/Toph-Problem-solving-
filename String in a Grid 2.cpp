#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
const ll mo=1e9+7;
ll go(ll a,ll b){
  ll re=1;
	while(b){
	if(b & 1) re*=a,re%=mo;
		a*=a;
		a%=mo;
		b/=2;
	}
	return re;
}
ll f[2501],in[2501];
int main() {
	ll i,j,k,n,m,t;
	cin>>n>>m;
	ll sum=0;
	for(i=0;i<n;i++){
	  for(j=0;j<m;j++){
		char c;
		  cin>>c;
		  if(c=='.') sum+=1;
	  }
	}
	string s;
	cin>>s;
	if(sum<s.size()){
	 cout<<0;
		return 0;
	}
	ll tmp[26]={0};
	for(i=0;s[i];i++) tmp[s[i]-97]+=1;
	f[0]=f[1]=1,in[0]=in[1]=1;
	for(i=2;i<=2500;i++){
	 f[i]=(f[i-1]*i)%mo;
	in[i]=go(f[i],mo-2);
	}
	n=s.size();
	ll re=f[sum];
	re=(re*in[sum-n])%mo;
	for(j=0;j<26;j++){
	  if(tmp[j]) re=(re*in[tmp[j]])%mo;	
	}
	cout<<re<<"\n";
	return 0;
}