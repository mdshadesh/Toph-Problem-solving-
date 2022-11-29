#include <stdio.h>

int main() 
{
	int tc,N,s,u,v;
	scanf("%d",&tc);
	while(tc--)
    {
		scanf("%d",&N);
    s=N/3;
	u=N-s;
	v=u/2;
	if(s<=u)
    {
	if(u%2!=0)
    {
		printf("%d %d %d\n",s,v,v+1);
	}
	else{
		printf("%d %d %d\n",s,v,v);
	}
	}
	}

	
	return 0;
}