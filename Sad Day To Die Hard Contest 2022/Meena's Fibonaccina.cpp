#include <bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define pb(x) push_back(x)
#define XX first
#define YY second
#define const 1000000007
#define PI 2*acos(0.0)
double a= PI;
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/a)*180 )
using namespace std;

int main()
{
    ll l,r; cin>>l>>r;
    ll xx= min(l,r); ll yy= max(l,r); l= xx; r= yy;
    ll lx= l;
    int ara[]={1,3,3,4,4,7,7,1,1,8,8,9,9,7,7,6,6,3,3,9,9,2,2,1};
    set<int>st;
    if(r<3){ cout<<r-l+1<<endl; exit(0); }
    if(l==0){ st.insert(1); st.insert(2); st.insert(3); }
    else if(l==1){ st.insert(2); st.insert(3); }
    else if(l==2)st.insert(3);
    if(l<3) l=3;
    if(r-l+1>=24){cout<<8<<endl; exit(0); }
    else{
        int i;
        for(i=l;i<=r;i++){
        int bl=ara[i%24]; st.insert(bl);
        }
        cout<<st.size()<<endl;
    }
    return 0;
}
