#include<stdio.h>
int main()
{
    long long a[3],d;
    scanf("%lld %lld %lld",&a[0],&a[1],&a[2]);
    d=a[0];
    for(int i=1;i<3;i++)
    {
        if(a[i]>d)
            d=a[i];
    }
    printf("%lld",d);
    return 0;
}