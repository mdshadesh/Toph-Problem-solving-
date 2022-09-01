#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define  pi  acos(-1.0)
#define   sf(a)         scanf("%d",&a)
#define   sf2(a,b)      scanf("%d%d",&a,&b)
#define   sf3(a,b,c)    scanf("%d%d%d",&a,&b,&c)
#define   sfl(a)        scanf("%llu",&a)
#define   sfl2(a,b)     scanf("%lld%lld",&a,&b)
#define   sfl3(a,b,c)   scanf("%lld%lld%lld",&a,&b,&c)
#define   fast          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll p(ll c)
{
    ll i,j;
    j=1;
    for(i=0;i<c;i++)
    {
        j=j*2;
    }
    return j;
}
int main()
{
    fast;
    ll i,j,k,l,t,n,a,b,v[65];
    sfl(t);
    while(t--)
    {
        sfl(n);
        for(i=0;i<n;i++)sfl(v[i]);
        ll cnt=0,ls=0,gn=0,tl=0;
        for(i=0;i<n;i++)
        {
            l=p(i);
            if(v[i]<l)
            {
                ls+=l-v[i];
            }
            else if(v[i]>l)
            {
                gn+=v[i]-l;
            }
            if(ls!=gn)cnt++;
            else
            {
                tl+=cnt;
                cnt=0;
            }
        }
        cout<<tl<<endl;
    }
    return 0;
}