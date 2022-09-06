#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc,t=0;
    double r;
    cin>>tc;
    while(tc--)
    {
        cin>>r;
        cout<<"Case "<<++t<<": ";
        cout<<setprecision(2)<<fixed<<r*r*(8-2*3.1416)<<endl;
    }
    return 0;
}