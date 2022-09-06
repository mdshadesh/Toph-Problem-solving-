#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long

int main()
{
	int a,b;string s="0123";
	string ss;int ma=0;
	do
	{
		cout<<s<<endl;
		cin>>a>>b;
		if(a==4 && b==0)return 0;
		if(a>ma){
			ma=a;
			ss=s;
		}
	} while (next_permutation(s.begin(), s.end()));
	s=ss;
	set<char> vv;
	for(char i='0';i<='9';i++){
		if(s[0]!=i && s[1]!=i && s[2]!=i && s[3]!=i){
			vv.insert(i);
		}
	}
	for(int i=0;i<4;i++){
		char tem=s[i];
		for(auto x:vv){
			s[i]=x;
			cout<<s<<endl;
			cin>>a>>b;
			if(a>ma){
				ss[i]=x;
				vv.erase(x);
				break;
			}
		}s[i]=tem;
	}
	cout<<ss<<endl;
	cin>>a>>b;
	if(a==4 && b==0){
		return 0;
	}
	return 0;
}