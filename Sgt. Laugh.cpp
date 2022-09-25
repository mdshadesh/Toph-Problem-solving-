#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, ans=1e9, k, h[mxN], g[mxN];
vector<ar<int, 2>> v;

struct ft {
	int a[mxN+1];
	void init() {
		memset(a, 0xc0, 4*n+4);
	}
	void upd(int i, int x) {
		for(++i; i<=n; i+=i&-i)
			a[i]=max(a[i], x);
	}
	int qry(int i) {
		int r=-1e9;
		for(; i; i-=i&-i)
			r=max(a[i], r);
		return r;
	}
} dp[29];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	if(k<2) {
		cout << 0;
		return 0;
	}
	for(int i=0; i<n; ++i) {
		cin >> h[i];
		v.push_back({h[i], -i});
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n; ++i)
		g[-v[i][1]]=i;
	for(int i=0; i<k-1; ++i)
		dp[i].init();
	for(int i=0; i<n; ++i) {
		//cout << g[i] << endl;
		dp[0].upd(g[i], v[g[i]][0]);
		for(int j=1; j<k; ++j) {
			int x=dp[j-1].qry(g[i]);
			if(j==k-1)
				ans=min(v[g[i]][0]-x, ans);
			else
				dp[j].upd(g[i], x);
		}
	}
	cout << (ans>=1e9?-1:ans);
}