#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() 
{
	string s;
	getline(cin,s);
	ll n = s.length();
	for(ll i=7; i<n-2; i++)
    {
		cout<<s[i];
	}
    cout<<endl;
	return 0;
}