#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    double ans;
    long long a,test;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&a);
        ans=(a*a)/2.0;
        printf("%.2f\n",ans);
    }

    return 0;
}