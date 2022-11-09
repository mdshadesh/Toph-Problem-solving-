#include <bits/stdc++.h>
using namespace std;

char s[505];
int n, dp[505][30][2];

int f(int i, int last, int dec) {
	if (i >= n)return 0;
	int &res = dp[i][last][dec]; if (~res)return res;
	res = f(i + 1, last, dec);
	if (dec == 0 && (last == 0 || s[i] - 'A' + 1 > last)) {
		res = max(res, f(i + 1, (s[i] - 'A') + 1, 0) + 1);
	}
	if ((last == 0 || s[i] - 'A' + 1 < last)) {
		res = max(res, f(i + 1, (s[i] - 'A') + 1, 1) + 1);
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)cin >> s[i];
		memset(dp, -1, sizeof dp);
		cout << f(0, 0, 0) << '\n';
	}
}