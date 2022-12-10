#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
ll brand[1010];
ll len[100];
ll ind[100][100];
 
ll sm[100][100];
ll md[100][100];
ll sd[100][100];
 
int main() {
	ll r, s, m, d, n, a, b, f = 0;
	cin >> r >> s >> m >> d >> n;
	for(int i = 1; i <= r; i++) {
		cin >> brand[i];
	}
	for(int i = 1; i <= s + m + d; i++) {
		cin >> len[i];
		for(int j = 1; j <= len[i]; j++) {
			cin >> ind[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		cin >> a >> b;
		if(a > b) {
			swap(a, b);
		}
		if(a <= s) {
			if(b <= s + m) {
				sm[a][b] = 1;
			}
			else {
				sd[a][b] = 1;
			}
		}
		else if(a <= s + m) {
			md[a][b] = 1;
		}
	}
	long double ans = 0;
	for(int i = 1; i <= s; i++) {
		for(int j = s + 1; j <= s + m; j++) {
			if(sm[i][j]) {
				continue;
			}
			for(int k = s + m + 1; k <= s + m + d; k++) {
				if(sd[i][k] || md[j][k]) {
					continue;
				}
				//    cout << "here " << i << " " << j << " " << k<< endl;
				int mp[r + 1];
				memset(mp, 0, sizeof mp);
				for(int it = 1; it <= len[i]; it++) {
					mp[ind[i][it]]++;
				}
				for(int it = 1; it <= len[j]; it++) {
					mp[ind[j][it]]++;
				}
				for(int it = 1; it <= len[k]; it++) {
					mp[ind[k][it]]++;
				}
				long double cur = 1;
				for(int it = 1; it <= r; it++) {
					if(!mp[it]) {
						continue;
					}
					cur *= brand[it];
					if(cur > 1e18) {
						f = 1;
						break;
					}
				}
				//      cout << "here " << cur << endl;
				ans += cur;
				if(ans > 1e18) {
					f = 1;
				}
			}
		}
	}
	//cout << "ttt " << ans << endl;
	if(f) {
		cout << "too many\n";
	}
	else {
		cout << setprecision(0) << fixed << ans << "\n";
	}
}