#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,s;
    int t,q;
    cin>>t;
    while(t--)
    {
        cin>>q;
    while(q--)
    {
       scanf("%lld %lld %lld",&n,&m,&s);
        cout<<n+((s-1)*m)<<endl;
    }
    }
    return 0;
}