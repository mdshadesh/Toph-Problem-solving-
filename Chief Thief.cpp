#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define ll long long

int main()
{
    ll n,i=0,product=1,temp,z_c=0;
    vector<ll> arr;

    scanf ("%lld",&n);
    while(i<n)
    {
        scanf ("%lld",&temp);
        arr.push_back(temp);
        if (temp==0) 
        z_c++;
        if (z_c<2 && temp!=0) 
        product*=temp;
        else if (z_c>=2) 
        product=0;
        i++;
    }
    for (i=0;i<n;i++)
    {
        if (z_c>1) printf ("0");
        else if (z_c==1)
        {
            if (arr[i]==0) 
            printf ("%lld",product);
            else 
            printf ("0");
        }
        else
        {
            printf ("%lld",product/arr[i]);
        }
        if (i==n-1) 
        printf ("\n");
        else 
        printf (" ");
    }
}