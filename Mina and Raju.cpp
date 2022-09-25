#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod=1e9+7;

ll dp[105][105];

int main()
{
	dp[0][0]=1;
	for(int i=1;i<105;i++)
    {
		dp[i][0]=1;
		for(int j=1;j<105;j++)
        {
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			if(dp[i][j]>=mod)dp[i][j]-=mod;
		}
	}
	int tc;
	cin>>tc;
	while(tc--)
    {
		int n,m,p,q,t;
		cin>>n>>m>>p>>q>>t;
		ll ans=0;

		for(int i=max(p,t-m);i<=t-q && i<=n;i++)
        {
			ans=(ans+dp[n][i]*dp[m][t-i])%mod;
		}
        cout<<ans<<endl;
	}
}