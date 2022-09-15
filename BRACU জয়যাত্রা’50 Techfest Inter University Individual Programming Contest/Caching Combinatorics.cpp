#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef APURBA
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 5000 +5;
const int mod = 998244353;
typedef pair<int,int> pii;

int stir[N][N];

int add(int x, int y)
{
    return (x+y>=mod ? x+y-mod:x+y);
}

int gun(int x, int y)
{
    return (x*1ll*y)%mod;
}

void stirling_number()
{
    stir[0][0] = 1;
    int lim = N;
    for(int i=1;i<lim;i++)
    {
        for(int j=0;j<=i;j++)
        {
            stir[i][j] = add( (j-1>=0?stir[i-1][j-1]:0) , gun(j, (j<=i-1?stir[i-1][j]:0)  )  );
        }
    }
}

int a[N];
int b[N];
int mp[N];
int ulta[N];

void TEST_CASES(int cas)
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        mp[a[i]] = i;
        ulta[i] = a[i];
        a[i] = i;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
        b[i] = mp[b[i]];
    }
    int len = 1;
    for(int i=n-1; i>=1; i--)
    {
        if(b[i] < b[i+1])
            len++;
        else
            break;
    }
    int ans = 0;
    int baki = n-len;
    for(int i=0;i<=len;i++)
    {
        ans = add(ans , stir[m][baki+i] );
    }
    cout<<ans<<"\n";
}
int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    stirling_number();
    int t=1,cas=0;
    cin>>t;
    while(t--)
    {
        TEST_CASES(++cas);
    }
    return 0;
}