#include <bits/stdc++.h>
using namespace std;

long long phi(int n)
{
    long long res = n;
    
    for(int i=2; i*i <= n; ++i)
    {
        if(n%i == 0)
        {
            while(n%i==0) n/=i;
            
            res -= (res/i);
        }
    }
    
    if(n>1) res -= (res/n);
    return res;
}
int main() {
    int t,k;
	long long int n,a;
	    
	cin>>t;
	while(t--)
	{
	    cin >> n >> k;
	    a = (k-1) * (phi(n));
	    cout << a << endl;
	    
	}
}