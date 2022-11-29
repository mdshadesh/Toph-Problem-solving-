#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define fastio ios_base::sync_with_stdio(false)
#define flush_off cin.tie(NULL)
#define mod 1000000007
ll t;
ll arr[30040];
map<ll,vector<pair<ll,ll>>>mp;
bool cmp(pair<ll,ll>x,pair<ll,ll>y)
{
	return x.first<y.first;
}

void solve()
{
	ll a;
	cin>>a;
	if(arr[a])
	{
		cout<<mp[a].size()<<endl;
		for(auto i:mp[a])
		{
			cout<<a<<' '<<i.first<<' '<<i.second<<endl;
		}
		return;

	}
	arr[a] = 1;
	ll A = a*a;
	for(ll i = a-2; i>0; i-=2)
	{
		if(A%i == 0)
		{
			ll x = i;
			ll y = A/i;
			if(x%2 != y%2) continue;
			ll b = (y-x)/2;
			ll c = (y+x)/2;
			
			if(__gcd(__gcd(a,b),c)>1 and b<A)
			{
				mp[a].push_back({b,c});
			}
		}
	}

	sort(mp[a].begin(), mp[a].end(),cmp);

	cout<<mp[a].size()<<endl;
	for(auto i:mp[a])
	{
		cout<<a<<' '<<i.first<<' '<<i.second<<endl;
	}
}

int main()
{
	fastio;
	flush_off; 
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif  
    memset(arr,0,sizeof(arr));
    cin>>t;
    while(t--) solve();
}