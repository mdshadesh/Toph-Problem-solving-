#include <iostream>

using namespace std;
#include<stdio.h>
#define ll long long int
int main()
{
    ll n,i,t,count;
    scanf("%lld",&t);
    while(t--){
            count=0;
    scanf("%lld",&n);
    for(i=2;i<n;i++){
        if(n%i==0){
            count++;
        }
    }
        if(count==0){
            printf("1\n");
        }
        else
            printf("0\n");
    }
}