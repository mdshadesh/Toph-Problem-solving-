#include <iostream>

using namespace std;
#include<stdio.h>
int main(){
 long long int i,j,k,m=0;
 int l;
 scanf("%lld%lld",&i,&j);
 if(i>=1 && j>=1 && i<=1000 && j<=1000){
    for(k=1;k<=(i*j);k++){
        scanf("%d",&l);
        if((l==0 || l==1)&& l==0){
            m++;
        }
    }
    printf("%lld\n",m);

 }

return 0;
}
