#include <iostream>
using namespace std;
int main()
{
	string s;
	long long n, i, j, k, q, p, l, a1 = 0, a2 = 0, b1 = 0, b2 = 0;
	cin >> n >> s;
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			if (s[i] == '1')
				a1++;
			else
				a2++;
		}
		else
		{
			if (s[i] == '1')
				b1++;
			else
				b2++;
		}
	}
	cin >> q;
	while (q--)
	{
		cin >> p;
		p--;
		if (p % 2 == 0)
		{
			if (s[p] == '1')
			{
				a1--;
				if (a1 < 0)
					a1 = 0;
				a2++;
				if (a2 > n)
					a2 = n;
				s[p] = '0';
			}
			else
			{
				a2--;
				a2 = max(0ll, a2);
				a1++;
				a1 = min(a1, n);
				s[p] = '1';
			}
		}
		else
		{
			if (s[p] == '1')
			{
				b1--;
				b1 = max(b1, 0ll);
				b2++;
				b2 = min(b2, n);
				s[p] = '0';
			}
			else
			{
				b2--;
				b2 = max(b2, 0ll);
				b1++;
				b1 = min(b1, n);
				s[p] = '1';
			}
		}
		cout << min(a1+b2,b1+a2)<< endl;
	}
}