#include<bits/stdc++.h>
using namespace std;

int ara[1000002];
int ans[1000002];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }
    ans[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        if(ara[i+1]-ara[i]>=2)
        {
            ans[i]=ans[i+1]+1;
        }else{
            ans[i]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(ans[i]==1) ans[i]=0;
        printf("%d\n",ans[i]);
    }
}