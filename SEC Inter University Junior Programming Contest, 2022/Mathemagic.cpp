#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const long long mod = 1e9+7ll;
long long n,pot[MAXN],v[MAXN];
unordered_map<int,int> freq;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	pot[0]=1;
	for(int i=1;i<MAXN;i++)pot[i]=(pot[i-1]<<1)%mod;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
		int a=v[i];
		for(int j=1;j*j<=a;j++){
			if(a%j==0)freq[j]++;
		}
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=(pot[freq[v[i]]]-1);
		ans%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}