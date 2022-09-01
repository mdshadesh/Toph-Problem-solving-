#include<bits/stdc++.h>
using namespace std;
#define endl        "\n"
#define ll long long

ll a[500010], r[500010], l[500010], rcost[500010], lcost[500010];
int main()
{
    ll n,h;
    cin>>n>>h;
    for(int i=1; i<=n; i++)
    {
        scanf("%lld", &a[i]);
        l[i]=max(a[i], l[i-1]+1);
        lcost[i]=(l[i]-a[i])+lcost[i-1];
    }
    for(int i=n; i>=1; i--)
    {
        r[i]=max(a[i], r[i+1]+1);
        rcost[i]=(r[i]-a[i])+rcost[i+1];

    }
    ll mn=LLONG_MAX, pp, f=0;
    for(int i=2; i<n; i++)
    {
     if(l[i-1]<h && r[i+1]<h && l[i]<=h && r[i]<=h)
       {
           pp=lcost[i-1]+ (h-a[i]) + rcost[i+1];
           mn=min(mn, pp);
           f=1;
       }
    }

    if(f==0) cout<<"-1"<<endl;
    else
    cout<<mn<<endl;
}
