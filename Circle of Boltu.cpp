#include <iostream>

using namespace std;

#include <stdio.h>
int main()
{
	int t,i,c,j,k;
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		scanf("%d",&c);
		long long int x[c],y[c],m=0,d;
		for (j=0;j<c;j++)
		scanf("%lld %lld",&x[j],&y[j]);
		for(j=0;j<c-1;j++)
		{
			for(k=j+1;k<c;k++)
			{
				d=(x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]);
				if(d>m) m=d;
			}
		}
		printf("Case %d: %lld\n",i,m);
	}
    return 0;
}