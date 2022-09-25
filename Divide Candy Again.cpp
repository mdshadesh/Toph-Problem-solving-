#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int t, cs = 0;
long long n;
void fib (long long n, long long &x, long long &y){
    if (n == 0) {
        x = 0;
        y = 1;
        return;
    }
    if (n & 1) {
        fib(n - 1, y, x);
        y = (y + x) % MOD;
    } else {
        long long a, b;
        fib(n >> 1, a, b);
        y = (a * a + b * b) % MOD;
        x = (a * b + a * (b - a + MOD)) % MOD;
    }
}
int main () {
    scanf("%d", &t); while (t--) {
        long long n; scanf("%lld", &n);
        long long x, y; fib(n + 2, x, y);
        long long res = 2LL * x - 2LL - n;
        res %= MOD, res *= 8LL, res %= MOD, res += MOD, res %= MOD;
        printf("Case %d: %lld\n", ++cs, res);
    }
	return 0;
}