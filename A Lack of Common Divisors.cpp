#include<bits/stdc++.h>
using namespace std;
int phi(int n)
{
    int ret=n;
    if(n%2==0)
    {
        while(n%2==0)
        {
            n/=2;
        }
        ret-=ret/2;
    }
    for(int i=3; i*i<=n+1; i+=2)
    {
        if(n%i==0){
            while(n%i==0)
            {
                n/=i;
            }
            ret-=ret/i;
        }
    }
    if(n>1) 
       ret=ret-ret/n;
    return ret;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", phi(n));
}