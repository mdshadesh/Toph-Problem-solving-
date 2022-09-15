#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
const long long INF = 1e9+7ll;
long long n,a[MAXN],b[MAXN],p[MAXN];
vector<int> grafo[MAXN],opz;
bool vis[MAXN];

int dfs(int nodo){
	if(vis[nodo])return INF;
	vis[nodo]=true;
	
	int res=p[nodo];
	for(auto i : grafo[nodo]){
		res=min(res,dfs(i));
	}
	return res;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[x]=i;
	}
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		b[x]=i;
	}
	
	for(int i=0;i<n;i++)cin>>p[i];
	
	
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			grafo[a[i]].push_back(b[i]);
			grafo[b[i]].push_back(a[i]);
		}
	}
	
	for(int i=0;i<n;i++){
		if(!vis[i]){
			opz.push_back(dfs(i));
		}
	}
	
	long long ans=0;
	
	if(opz.size()==1){
		cout<<"0\n";
		return 0;
	}
	
	sort(opz.begin(),opz.end());
	
	for(auto i : opz){
		ans+=i;
	}
	ans+=(long long)(opz.size()-2)*opz[0];
	
	cout<<ans<<"\n";

	return 0;
}