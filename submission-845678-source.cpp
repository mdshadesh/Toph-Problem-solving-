// Naimul Hasan Shadesh
// Sonargaon University 

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll i=0;
    ll j = 1000000 ;
    string s;
    ll n;
    while(i<=j)
    {
        n =  (i+j)/2;
        printf("%lld\n",n);
        cin>>s;
        if(s=="Bigger"){
            i = n +1;
        }
        else if(s=="Smaller"){
            j = n-1;
        }
        else{
            return 0;
        }
    }
}