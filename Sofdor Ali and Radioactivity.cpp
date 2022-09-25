#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
void mul(ll a[51][51],ll b[51][51],ll m)
{
    ll i,j,k;
    ll res[m][m];
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            res[i][j]=0;
            for(k=0;k<m;k++)
            res[i][j]=(res[i][j]+a[i][k]*b[k][j])%mod;
        }
    }
    for(i=0;i<m;i++)
    for(j=0;j<m;j++)
    a[i][j]=res[i][j];
}
void expo(ll a[51][51],ll n,ll m)
{
    ll res[51][51];
    ll i,j;
    for(i=0;i<m;i++)
    for(j=0;j<m;j++)
    {
        if(i==j)
        res[i][j]=1;
        else
        res[i][j]=0;
    }
    while(n>0)
    {
        if(n&1)
        mul(res,a,m);
        mul(a,a,m);
        n/=2;
    }
    for(i=0;i<m;i++)
    for(j=0;j<m;j++)
    a[i][j]=res[i][j];
}
int main()
{
    ll t,n,m,i,j,k;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n>>m;
        if(m==0)
        {
            cout<<"Case "<<i<<": ";
            cout<<0<<endl;
            continue;
        }
        ll a[51][51];
        ll d[m];
        d[0]=1;
        for(j=1;j<m;j++)
        d[j]=(2*d[j-1])%mod;
        if(n<m)
        {
            cout<<"Case "<<i<<": ";
            cout<<d[n-1]<<endl;
            continue;
        }
        for(j=0;j<m;j++)
        {
            for(k=0;k<m;k++)
            {
                if(j==0)
                a[j][k]=1;
                else if(k==j-1)
                a[j][k]=1;
                else
                a[j][k]=0;
            }
        }
        expo(a,n-m,m);
        ll ans=0;
        for(j=0;j<m;j++)
        ans=(ans+a[0][j]*d[m-1-j])%mod;
        cout<<"Case "<<i<<": ";
        cout<<ans<<endl;
    }
}