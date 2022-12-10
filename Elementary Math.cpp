#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 3e3 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

unordered_map <ll, ll> mp, used;
int x[Max];
int y[Max];
char sym[Max];
ll res[Max];

bool solve(int idx) {
	for(char ch : {
				'+', '-', '*'
			}) {
		ll sum = x[idx];
		if(ch == '+') {
			sum += y[idx];
		}
		else if(ch == '-') {
			sum -= y[idx];
		}
		else {
			sum *= y[idx];
		}
		if(!used[sum]) {
			used[sum] = 1;
			if(!mp[sum] || solve(mp[sum])) {
				mp[sum] = idx;
				sym[idx] = ch;
				res[idx] = sum;
				return true;
			}
		}
	}
	return false;
}

int main() {
#ifdef Mr_Emrul
	freopen("inputf.in", "r", stdin);
#endif /// Mr_Emrul

	int n, match = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		if(solve(i)) {
			match++;
		}
		used.clear();
	}
	if(match < n) {
		printf("impossible\n");
	}
	else {
		for(int i = 1; i <= n; i++) {
			printf("%d %c %d = %lld\n", x[i], sym[i], y[i], res[i]);
		}
	}
	return 0;
}