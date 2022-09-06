#include <bits/stdc++.h>
#define ll long long int
#define md 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll T = 1, n, i, cs = 1, m;
	cin >> T;
	string s;
	while(T--)
	{
	    cin >> n;
	    if(n == 2)  cout << "-1\n";
	    else if(n & 1)
	    {
	        for(i=0; i<n-2; i++)  cout << "1 ";   
	        if(n > 1)   cout << "2 ";
	        cout << n << '\n';
	    }
	    else
	    {
	        for(i=0; i<n-3; i++)  cout << "1 ";   
	        cout << "2 2 " << n+1 << '\n';
	    }    
    	}
	return 0;
}