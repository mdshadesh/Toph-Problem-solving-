#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int ask(int l, int r) 
{
	cout << "0 " << l+1 << " " << r+1 << endl;
	int x;
	cin >> x;
	return x;
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int x=ask(0, n-1);
	int lb=0, rb=n-1;
	while(lb<rb) 
    {
		int mb=(lb+rb)/2;
		if(ask(mb, mb)>=x)
			rb=mb;
		else
			lb=mb+1;
	}
	cout << "1 " << x << " " << lb+1;
}