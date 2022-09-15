#include <bits/stdc++.h>
using namespace std;

#define pi                              acos(-1.0)
#define rep(i, a, n)                    for (int i = a; i < n; i++)
#define per(i, a, n)                    for (int i = n - 1; i >= a; i--)
#define Long                            long long
#define all(x)                          (x).begin(), (x).end()

const int Nn = 1e6 + 7;
const Long MOD = 1e9 + 7;
void solve(int t) 
{
    int N;
    cin >> N;
    int A[N], Ans = INT_MAX;
    for (int i = 0; i < N; ++i)  cin >> A[i];
    sort(A, A + N);
    vector <bool> done(N, false);
    for (int i = 0; i < N; ++i) {
        if (done[i]) continue;
        int x = A[i] + A[i];
        int ii = i + 1;
        while (true) {
            int jj = lower_bound(A + ii, A + N, x) - A;
            if (jj == N || A[jj] != x) {
                Ans = min(Ans, x);
                break;
            }
            done[jj] = true;
            x += A[i];
            ii = jj + 1;
        }
        if (A[i] == 1) break;
    }

    cout << Ans << "\n";
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(12);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)   
         solve(i);
    return 0;
}