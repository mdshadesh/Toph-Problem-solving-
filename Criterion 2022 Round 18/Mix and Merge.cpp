#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105, MAXK = 51, INF = INT_MAX/3;
int t,n,k,a[MAXN],pref[MAXN],dp[MAXN][MAXN][MAXK];

int f(int l,int r,int num){
	if(num==0)return INF;
	if(dp[l][r][num]!=0)return dp[l][r][num];
	if(r-l+1<=num)return pref[r]-pref[l-1];
	if(num==1)return dp[l][r][num] = pref[r]-pref[l-1]+f(l,r,k);
	
	int ans=INT_MAX;
	for(int i=l+1;i+1<r && (i-(l+i)<=k+3);i++){
		ans=min(ans,f(i+1,r,num-1)+f(l,i,k)+pref[i]-pref[l-1]);
	}
	
	ans=min(ans,f(l+1,r,num-1)+pref[l]-pref[l-1]);
	ans=min(ans,f(l,r-1,k)+pref[r]-pref[l-1]);
	ans=min(ans,INF);
	
	return dp[l][r][num]=ans;
}

void solve(int t){
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++)pref[i]=pref[i-1]+a[i];
	
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)for(int z=0;z<=k;z++)dp[i][j][z]=0;
	
	if(n==1)cout<<"Case "<<t<<": "<<0<<"\n";
	else cout<<"Case "<<t<<": "<<f(1,n,k)<<"\n";
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>t;
	
	for(int i=1;i<=t;i++)solve(i);

	return 0;
}