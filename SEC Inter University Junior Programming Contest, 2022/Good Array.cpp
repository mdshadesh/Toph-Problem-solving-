#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define mx 200000
const int MOD =  1e9+7;
ll fact[mx];
ll bigmod (ll b, ll p)
{
    if (p==0) return 1;
    if (p%2==0) {
        ll x=bigmod(b, p/2)%MOD;
        return (x*x)%MOD;
    }
    else return (b%MOD * bigmod(b, p-1))%MOD;
}
ll modInverse(ll a, ll m)
{
    return bigmod(a, m-2);
}
void facto(ll n){
    fact[0]=1;
    for(ll i=1;i<=n;i++){
        fact[i]=(fact[i-1]*i)%MOD;

    }
}
ll ncr(ll n,ll k){

     return (fact[n]*modInverse((fact[k]*fact[n-k])%MOD,MOD))%MOD;

}
void solve(){
    ll n,k;
    cin>>n>>k;
    if(n%2) {cout<<"0\n";return ;}
    ll ans=bigmod(k,n)%MOD,temp=0;
    for(ll i=n/2+1;i<=n;i++){
         temp=(temp+(ncr(n,i)*bigmod((k-1),n-i))%MOD)%MOD;
    }
    ans=(ans-(temp*k)%MOD)%MOD;
    ans=(ans%MOD+MOD)%MOD;
    cout<<ans<<'\n';
}
int main() {
    ll t=1;
    facto(100100);
    cin>>t;
    for(ll i=0;i<t;i++) solve();
}