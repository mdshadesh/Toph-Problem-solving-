// Naimul Hasan SHadesh
// Sonargaon University

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s;
	cin >> s;

	int con = 0;
	for(int i = 0; i < s.length(); i++)
	{
		switch(tolower(s[i]))
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				con++;
				break;
		}
	}

	cout << con << endl;

	return 0;
}