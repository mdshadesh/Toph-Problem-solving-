#include<bits/stdc++.h>
using namespace std;

#define f(i, n) for(int i = 1; i <= n; i++)
#define fab(i, a, b) for(int i = a; i <= b; i++)
#define rf(i, n) for(int i = n; i >= 0; i--)
#define rfab(i, a, b) for(int i = b; i >= a; i--)

int arr[505];
vector<int> q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif 

    int t;
    cin >> t;

    f(tests, t) {
        int n;
        cin >> n;

        long long toCount = n/2;
        long long ans = (toCount * (toCount + 1));

        if(n & 1) {
            ans += ((n + 1)/2);
        }

        cout << ans << endl;
    }
}
