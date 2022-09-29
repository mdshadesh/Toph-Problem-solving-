#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, mxM=5e5;
int n, m, a[mxN], ql[mxM], qr[mxM];
ll ans[mxM];
vector<ar<int, 2>> ev;

struct ft {
	ll a[mxN+1];
	void upd(int i, ll x) {
		for(++i; i<=n; i+=i&-i)
			a[i]+=x;
	}
	ll qry(int i) {
		ll r=0;
		for(; i; i-=i&-i)
			r+=a[i];
		return r;
	}
} b0, b1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		ev.push_back({a[i], -i-1});
	}
	for(int i=0; i<m; ++i) {
		int c;
		cin >> ql[i] >> qr[i] >> c, --ql[i], --qr[i];
		ev.push_back({c, i});
	}
	sort(ev.begin(), ev.end());
	for(ar<int, 2> e : ev) {
		if(e[1]<0) {
			e[1]=-e[1]-1;
			b0.upd(e[1], 1);
			b1.upd(e[1], e[0]);
		} else {
			ans[e[1]]=e[0]*(b0.qry(qr[e[1]]+1)-b0.qry(ql[e[1]]))-(b1.qry(qr[e[1]]+1)-b1.qry(ql[e[1]]));
		}
	}
	for(int i=0; i<m; ++i)
		cout << ans[i] << "\n";
}