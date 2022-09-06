#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,l=0;
        cin>>x;
        while(x>0)
        {
            x=x/2;
            l++;
        }
        cout << "Case "<<i<<": "<<l<<endl;
    }
    return 0;
}