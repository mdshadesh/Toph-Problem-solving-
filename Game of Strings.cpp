#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int n;cin>>n;set<string> st;
	while(n--)
    {
		string s;
		cin>>s;st.insert(s);
	}
	int k;cin>>k;
	for(string x:st)
		if(k>0)cout<<x,k--;
        
	cout<<endl;
}