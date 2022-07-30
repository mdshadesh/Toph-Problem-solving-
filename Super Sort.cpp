#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
#define ll long long
#define PI acos(-1)
#define N 1000000007


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ar[n];
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        sort(ar,ar+n);
        for(int i=0;i<n-1;i++)
        {
            if(abs(ar[i]-ar[i+1])<=k)
                continue;
            else
            {
                flag=false;
                break;
            }
        }
        if(flag==false)
            cout<<"No Solution"<<endl;
        else
        {
            for(int i=0;i<n-1;i++)
                cout<<ar[i]<<" ";
            cout<<ar[n-1]<<endl;
        }
    }
    return 0;
}