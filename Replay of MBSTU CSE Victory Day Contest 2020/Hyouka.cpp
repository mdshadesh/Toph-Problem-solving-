#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,ii,k;

bool func(int need)
{
	int koy=0;
	for(int i=1;i<=n;i++)koy+=ar[i]/need;
	return koy>=k;
}

void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
	int be=1,en=mod;
    int re=be;
    while(be<=en)
    {
    	int mid=(be+en)/2;
    	if(func(mid))
    	{
    		re=mid;
    		be=mid+1;
    	}
    	else en=mid-1;
    }
    printf("%d\n",re );
}

int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}