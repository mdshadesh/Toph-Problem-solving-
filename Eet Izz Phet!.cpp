#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	string s;
	set<string>u;
	cin>>n;
	while (n--)
    {
		cin>>s;
		u.insert(s);
	}
	cin>>m;
	while (m--)
    {
		cin>>s;
		if (u.find(s)!=u.end()) 
           cout<<"yes\n";
		else 
           cout<<"no\n";
	}
	return 0;
}