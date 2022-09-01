#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,k,i,index,vag,first,second,ans1=0,ans2=0,ans;
    cin>>n>>k;
    ll pre[n];
    for(i=0; i<n; i++)
        {
            cin>>pre[i];
        }

    sort(pre,pre+n);

    index=n/2;
    vag=pre[index]/k;
    first=vag*k;
    second=k*(vag+1);

    for(int i=0; i<n; i++)
    {
        ans1+=abs(pre[i]-first);
        ans2+=abs(pre[i]-second);
    }

    ans=min(ans1,ans2);
    cout<<ans<<endl;
    return 0;
}