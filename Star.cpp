#include <iostream>
using namespace std;

int main() 
{
	long long r, c;
	cin >> r >> c;
	long long a = min(r, c);
	cout << (a - 1) * 4 + 1 << endl;
	return 0;
}