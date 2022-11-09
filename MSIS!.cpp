#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, a[mxN];
ll ft[mxN+1];
ar<int, 2> b[mxN];

void upd(int i, ll x) {
	for(++i; i<=n; i+=i&-i)
		ft[i]=max(ft[i], x);
}

ll qry(int i) {
	ll r=0;
	for(; i; i-=i&-i)
		r=max(ft[i], r);
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		b[i]={a[i], -i};
	}
	sort(b, b+n);
	for(int i=0; i<n; ++i) {
		int p=lower_bound(b, b+n, ar<int, 2>{a[i], -i})-b;
		upd(p, qry(p)+a[i]);
	}
	cout << qry(n);
}