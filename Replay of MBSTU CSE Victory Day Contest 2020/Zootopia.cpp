#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int tc=1;
ll dp[19][2][512][163];
int casio[19][2][512][163];
string s;
int n,m;
ll f(int pos,int x,int mask,int sum){
	if(pos==-1){
		if(mask==0)return 0;
		int ss=0;
		for(int i=0;i<9;i++){
			if(mask&(1<<i)){
				ss+=(i+1);
			}
		}
		return sum%ss==0;
	}
	ll &ss=dp[pos][x][mask][sum];
	if(~ss){
		if(x==0)return ss;
		else if(casio[pos][x][mask][sum]==tc)return ss;
	}
	casio[pos][x][mask][sum]=tc;
	ss=0;
	for(int i=0;(!x && i<=9) || (x && i<=s[pos]-'0');i++){
		ss+=f(pos-1,((x && i!=s[pos]-'0')+x)&1,(i==0?mask:mask|(1<<(i-1))),sum+i);
	} return ss;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	s="1"+string(18,'0');
	reverse(s.begin(), s.end());
	n=s.size();
	memset(dp,-1,sizeof dp);
	f(n-1,1,0,0);
        tc++;



	int t; cin>>t; while(t--){
		string l,r;
		cin>>l>>r;
		s=r;
		reverse(s.begin(), s.end());
		n=s.size();
		ll an=f(n-1,1,0,0);
		tc++;
		s=l;
		reverse(s.begin(), s.end());
		n=s.size();
		an-=f(n-1,1,0,0);
		tc++;

		int aa[10]={0},st=0,stt=0;
		for(auto x:l){
			st+=x-'0';
			aa[x-'0']++;
			if(aa[x-'0']==1)stt+=x-'0';
		}an+=(st%stt==0);
		cout<<an<<endl;
	}
	return 0;
}