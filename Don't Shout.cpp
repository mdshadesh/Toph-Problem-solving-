#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	while(cin >> s) {
		int f = 0;
		for(char c : s) if(c > 96) f = 1;
		if(f) cout << s << ' ';
	}
}