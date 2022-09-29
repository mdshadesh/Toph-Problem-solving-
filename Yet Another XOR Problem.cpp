#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 500005;

int n, i, tab[N], a, b, maxx;
VI graf[N];
multiset<int> s;
multiset<int>::iterator it;

void get(int w) {
	//printf("%d\n", w);
	int res = 0, val = 0;
	for (int i=29;i>=0;i--) {
		if (tab[w] & (1<<i)) {
			it = s.lower_bound(val);
			if (it != s.end() && *it < val + (1<<i)) res += (1<<i); else val += (1<<i);
		} else {
			it = s.lower_bound(val + (1<<i));
			if (it != s.end() && *it < val + 2 * (1<<i)) {
				res += (1<<i);
				val += (1<<i);
			}
		}
	}
	maxx = max(maxx, res);
}

void go(int w, int o) {
	if (s.size() > 0) get(w);
	s.insert(tab[w]);
	for (auto& w2 : graf[w]) if (w2 != o) go(w2, w);
	s.erase(s.find(tab[w]));
}

int main() {
scanf("%d", &n);
for (i=1;i<=n;i++) scanf("%d", &tab[i]);
for (i=1;i<n;i++) {
	scanf("%d %d", &a, &b);
	graf[a].pb(b);
	graf[b].pb(a);
}
maxx = 0;
go(1, -1);
printf("%d\n", maxx);
return 0;
}