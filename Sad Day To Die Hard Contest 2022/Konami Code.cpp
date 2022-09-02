#include <bits/stdc++.h>
 
using namespace std;
#define maxn 100010
#define INF 1e15
#define ff first
#define ss second
#define endl '\n'
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string kon = "UUDDLRLRBA";
	string s;
	cin >> s;
	int pos = s.find(kon);
	int ans = 0;
	while (pos != -1) {
		ans++;
		pos = s.find(kon, pos + 1);
	}
	cout << ans << endl;
}