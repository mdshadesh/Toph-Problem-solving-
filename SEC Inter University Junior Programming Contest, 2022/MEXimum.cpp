#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
long long n,a[MAXN],ans;
map<long long,int> ok;
vector<int> grafo[MAXN];
set<long long> pq;

void dfs(int nodo,int last,long long mex){
	ok[a[nodo]]++;
	
	if(ok[a[nodo]]==1)pq.erase(a[nodo]);
	
	ans=max(ans,*pq.begin());
	
	for(auto i : grafo[nodo]){
		if(i!=last){
			dfs(i,nodo,mex);
		}
	}
	
	ok[a[nodo]]--;
	if(ok[a[nodo]]==0)pq.insert(a[nodo]);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i=0;i<MAXN;i++){
		pq.insert(i);
	}

	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=min(a[i],100004ll);	
	}
	
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	
	dfs(1,-1,0);

	cout<<ans<<"\n";

	return 0;
}