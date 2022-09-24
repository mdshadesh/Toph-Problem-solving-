#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> vc;
    int arr[n+10][n+10];
    for(int i=0; i<n; i++ )
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
            vc.push_back(arr[i][j]);
        }
    }
    sort(vc.begin(),vc.end());
    int res = 0,res2 = 0;

    if(n%2==1)
    {
        for(int i=vc.size()-1; i>=vc.size()-n; i-- )
            res+=vc[i];
        for(int i=0; i<n-1; i++)
            res2+=vc[i];
        res2+=vc[vc.size()-n];
    }
    else
    {
        for(int i=vc.size()-1; i>=vc.size()-n; i-- )
            res+=vc[i];
        for(int i=0; i<n; i++)
            res2+=vc[i];
    }

    cout<<res - res2<<endl;
    return 0;
}