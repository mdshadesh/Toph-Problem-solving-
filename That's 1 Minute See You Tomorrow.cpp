#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,a;
    cin>>n>>m;
    for(i=0; i<n; i++)
    {
        cin>>a;
        if(a<m)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    a=n*m;
    if(a==60)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}