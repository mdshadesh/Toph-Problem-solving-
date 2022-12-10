#include<bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    long long n;
    cin >> n;
    while(n--)
    {
        long long p,c;
        cin >> p;
        if(p%2==0)
            cout << (-1)*(p/2) << nl;
        else cout << ((-1)*(p/2))+1 << nl;
    }
    return 0;
}