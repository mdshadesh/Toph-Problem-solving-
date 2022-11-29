#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
	  long long p, d;
	  cin >> p >> d;
	  long long q = p + d;
	  long long r = p - d;
	  if (q % d == 0LL && (q / d) % d == 0LL) {
	    cout << "Yes\n";
	  } else if (r % d == 0LL && (r / d) % d == 0LL) {
	     cout << "Yes\n";
	  } else {
	    cout << "No\n";
	  }
	}
	return 0;
}