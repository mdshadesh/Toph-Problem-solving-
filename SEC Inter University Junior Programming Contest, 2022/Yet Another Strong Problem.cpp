#include <bits/stdc++.h>
using namespace std;

struct mat{
	int v[105][105];
	mat operator*(const mat& other) const{
		mat res;
		for(int i=0;i<105;i++){
			for(int j=0;j<105;j++){
				res.v[i][j]=0;
				for(int z=0;z<105;z++){
					res.v[i][j]+=v[i][z]*other.v[z][j];
				}
				res.v[i][j]&=1;
			}
		}
		return res;
	}
};
mat fastp(mat base,long long exp){
	if(exp==1)return base;
	mat tmp = fastp(base,exp/2);
	tmp = tmp*tmp;
	if(exp%2==1)tmp = tmp*base;
	return tmp;
}
string s;
long long n,ans[105];
mat st,passo;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s >> n;
	if(n==0){
		cout<<s<<"\n";
		return 0;
	}
	st.v[0][104]=1;
	for(int i=0;i<s.size();i++){
		st.v[0][i]=s[i]-'0';
	}
	for(int i=1;i<((int)s.size())-1;i++){
		if(i-1>0)passo.v[i-1][i]=1;
		if(i+1<((int)s.size())-1)passo.v[i+1][i]=1;
		
		passo.v[i][i]=1;
		passo.v[104][i]=1;
	}
	passo.v[104][104]=1;
	mat sol = st * fastp(passo,n);
	for(int i=0;i<s.size();i++)ans[i]=sol.v[0][i];
	for(int i=0;i<s.size();i++){
		if(ans[i])cout<<'1';
		else cout<<'0';
	}
	cout<<'\n';
	return 0;
}