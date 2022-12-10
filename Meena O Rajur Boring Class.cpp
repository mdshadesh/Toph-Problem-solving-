#include<bits/stdc++.h>
#define ll long long
#define pi 3.141593
using namespace std;

int main()
{
    long long int n,i,x,j;
    cin>>x;
    while(x--)
    {
        long double sum=0.0,k;
        cin>>n;

        long long int ar[40];
        ar[0]=0;
        ar[1]=1;
        for(i=1; i<=n; i++)
        {
            j=ar[i]+ar[i-1];
            ar[i+1]=j;
            k=ar[i];
            sum += (k*k - (pi*k*k)/4);
        }

        printf("%0.2llf\n", sum);
    }
    return 0;
}