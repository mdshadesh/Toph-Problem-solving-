#include <bits/stdc++.h>
using namespace std;
int main ()
{
	long long test,i,j,k,num,cnt=0;
	cin>>num;
	map <string, long long> mp;
	for (i=1; i<=num; i++)
	{
		string str;
		cin>>str;
		mp[str]+=1;
	}
	for (i=1; i<=num; i++)
	{
		string s;
		cin>>s;
		if(mp[s]!=NULL)
		{
			mp[s]-=1;
			cnt+=1;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
