#include<bits/stdc++.h>
using namespace std;

long long ara[27][1000005];
int tra[27][1000005],nra[27][1000005];

int main()
{
    char ss[1000007];
    long long n,m,q,i,j,k,l,r,a,b,c,d,e,f,cnt,ssum,ttl,ans;
    scanf("%s",ss);  n=strlen(ss);
    for(j=25;j>=1;j--)
    {
        cnt=0; ttl=0; ssum=0;
        for(i=n;i>=1;i--)
        {
            k=ss[i-1]-97;
            if(k<j)cnt++;
            if(k==j){  ttl++;   ssum=ssum+cnt;  }
            ara[j][i]=ssum;  tra[j][i]=cnt;  nra[j][i]=ttl;
        }
    }
    scanf("%lld",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%lld %lld",&l,&r);  ans=0;
        for(j=25;j>=1;j--)
        {
            a=ara[j][l]-ara[j][r+1]; b=tra[j][r+1]; c=nra[j][l]-nra[j][r+1];
            d=c*b;  a=a-d;  ans=ans+a;
        }
        printf("%lld\n",ans);
    }
    return 0;
}