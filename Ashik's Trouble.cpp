#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int test=0;test<t;test++)
    {
        int n,m,a,b,c;
        cin >> n >> m;
        n/=2;
        a = n*n;
        b = a*3*2;
        c = a*2*(m-2);
        cout << b+c << "\n";
    }
}