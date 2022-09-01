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

    int n;

    while(cin >> n) {
        A.clear();
        B.clear();

        f(i, n) {
            int a;
            cin >> a;
            A.push_back(a);
        }

        f(i, n) {
            int a;
            cin >> a;
            B.push_back(a);
        }

        sort(A.rbegin(), A.rend());
        sort(B.begin(), B.end());

        cout << A[0] + B[0];

        fab(i, 1, n - 1) {
            cout << " " << A[i] + B[i];
        }

        cout << endl;
    }
}
