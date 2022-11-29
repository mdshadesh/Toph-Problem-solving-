#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " : " << x << endl
#define ll long long
int n, m, x, y, p, q, z, a, b, xx, i, j, yy, ans, v[200][200];
int main ()
{
	cin >> n >> m >> x >> y >> p >> q >> z; ans = 0;
	for(i = 1; i <= z; i++)
	{
		cin >> a >> b;
		v[a][b] = -1;
	}
	int dx[10] = {p, p, -p, -p, q, q, -q, -q};
	int dy[10] = {q, -q, q, -q, p, -p, p, -p};
	for(i = 0; i < 8; i++)
	{
		xx = x + dx[i];
		yy = y + dy[i];
		if((xx <= n and xx > 0) and (yy > 0 and yy <= m) and (v[xx][yy] != -1))
		{
			ans++;
			v[xx][yy] = -1;
		}
	}
	cout << ans << endl;
}