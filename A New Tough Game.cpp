#include <bits/stdc++.h>
using namespace std;

int32_t main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	string ans;
	string q(n, 'a');
	int yp;
	for (int i = 0; i < n; i++) 
    {
		if (i == 0) 
        {
			cout << "? " << q << endl;
			cin >> yp;
		}
		q[i] = 'z';
		cout << "? " << q << endl;
		int xp; cin >> xp;
		int y = (yp - xp + 25) / 2;
		ans += 'a' + y;
		q[i] = 'a';
	}
	cout << "! " << ans << endl;
}