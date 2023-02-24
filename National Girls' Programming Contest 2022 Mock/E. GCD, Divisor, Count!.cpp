#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int power(int a, long long b) {
	int x = 1;
	while (b) {
		if (b & 1)x = 1LL * x * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	} return x;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t; while(t--) {
		int n; long long a, b; cin >> n >> a >> b;
		if(b % a != 0) {
			cout << 0 << '\n';
		} else {
			a = b / a;
			int ans = 1;
			for(int i = 2; 1LL * i * i <= a; i++) {
				int x = 0;
				while(a % i == 0) {
					a /= i;
					x++;
				}
				if(x) {
					int val = power(x + 1, n) - power(x, n);
					if(val < 0) val += mod;
					ans = 1LL * ans * val % mod;
				}
			}
			if(a != 1) {
				int x = 1;
				int val = power(x + 1, n) - power(x, n);
				if(val < 0) val += mod;
				ans = 1LL * ans * val % mod;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}