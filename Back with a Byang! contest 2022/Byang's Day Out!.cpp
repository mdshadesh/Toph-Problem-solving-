#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b>=c && b+c>=a && c+a>=b)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;

    }
    return 0;
}