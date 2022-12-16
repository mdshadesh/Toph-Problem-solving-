#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ar[600005];
vector<ll>v;
int main()
{
    ll n, q, k, ans, i, sum=0;

    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>ar[i];
    }
    sort(ar,ar+n+1);

    for(i=1; i<=n; i++)
    {
        sum+=ar[i];
        v.push_back(sum/i);
    }

    cin>>q;

    while(q--)
    {
        cin>>k;
        ans=upper_bound(v.begin(),v.end(),k-1)-v.begin();
        cout<<ans<<endl;
    }
}