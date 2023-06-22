#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    long long a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        if(a[i]>b[i])swap(a[i],b[i]);
    }
    while(m--)
    {
        long long c=0,l,r,ca,cb;
        cin>>l>>r;
        if(l>r)swap(l,r);
        for(int i=0;i<n;i++)
        {
            if(a[i]<=r&&b[i]>=l)c++;
        }
        cout<<c<<endl;
    }
}