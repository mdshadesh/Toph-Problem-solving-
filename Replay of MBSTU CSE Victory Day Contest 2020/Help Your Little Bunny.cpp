#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
const int mod=1e9+7;
long long fact[N];

void PreCal()
{
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%mod;
}
long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
long long nCr(int n,int r)
{
    return (fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    long long ans;
    PreCal();
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> n;
        cout << "Case #" << i << ": ";
        if(n & 1)cout << "my Little Bunny is lost\n";
        else
        {
            ans=nCr(n,n/2);
            ans-=nCr(n,n/2+1);
            if(ans < 0)ans+=mod;
            cout << ans << '\n';
        }
    }
    return 0;
}