#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,a;
        double ans;
        cin>>r>>a;
        ans=(acos(-1)*r*r*a)/360;
        cout<<fixed<<setprecision(9)<<ans<<endl;
    }
    return 0;
}