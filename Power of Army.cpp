#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int a;
    cin>>a;
    while(a--)
    {
        int n;
        cin>>n;
        int ar[n+2];
        for(int i=0; i<n; i++)
        {
            cin>>ar[i];
        }
        sort(ar,ar+n);
        cout<<ar[n-1]-ar[0]<<endl;
    }
}