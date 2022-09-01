#include<bits/stdc++.h>
using namespace std;

#define f(i, n) for(int i = 1; i <= n; i++)
#define fab(i, a, b) for(int i = a; i <= b; i++)
#define rf(i, n) for(int i = n; i >= 0; i--)
#define rfab(i, a, b) for(int i = b; i >= a; i--)

vector<int> A, B;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif 

    long long n;

    while(cin >> n) {
        long long point = n / 2;

        cout << point << " " << point << endl;
        cout << point << " " << (-1) * point << endl;
        cout <<(-1) *  point << " " << point << endl;
        cout <<(-1) *  point << " " <<(-1) *  point << endl;
    }
}
