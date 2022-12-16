#include<bits/stdc++.h>
using namespace std;
#define  ll long long
int main()
{
    ll n,t,tc=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ++tc;
        ll ans = (n*(n-1)*(n-2)*(n-3))/24;
        printf("Case %lld: %lld\n",tc,ans);
    }
    return 0;
}