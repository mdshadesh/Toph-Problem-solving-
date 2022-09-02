#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
    {
		int ax,ay;
		cin>>ax>>ay;
		int s1,s2,p1,p2;
		cin>>s1>>s2>>p1>>p2;

		double h,h1,h2,h3;
		h = hypot(s1+p1,s2-p2);
		h1=hypot(p1-s1,p2+s2);
		h2=hypot(p1 - 2*ax + s1,p2-s2);
		h3=hypot(p1-s1,p2-2*ay+s2);
		double ans;
		ans=h;
		if(ans > h1) 
           ans = h1;
		if(ans > h2) 
           ans = h2;
		if(ans > h3) 
           ans = h3;
		cout<<ans<<endl;
	}
	return 0;
}