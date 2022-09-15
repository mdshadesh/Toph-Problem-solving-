#include<bits/stdc++.h>
using namespace std;
#include <stdio.h>

int main()
{
    int n, x = 1;
    long a,b;
    scanf("%d",&n);
    if(n<1)
        return 0;
    if(n==1)
    {
        printf("1");
        return 0;
    }
    printf("1");
    scanf("%ld",&b);
    for(;n>1;n--)
    {
        scanf("%ld",&a);
        if(a>b)
            x++;
        else
            x=1;
        printf(" %d",x);
        b=a;
    }

    return 0;
}