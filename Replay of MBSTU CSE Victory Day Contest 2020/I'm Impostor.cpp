#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Problem F
const ll mod = (ll) 1e9 + 7;
const ll nax = (ll)1e6 + 7;
ll power (ll v, ll p) {
    ll res = 1;
    while (p) { if (p & 1) res = (res * v) % mod; p = p >> 1; v = (v * v) % mod; } return res;
}
vector<ll> fact, ifact;
void factorial (const int N) {
    fact.resize (N + 1); ifact.resize(N + 1); fact[0] = ifact[0] = 1LL;
    for (ll i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % mod; ifact[N] = power(fact[N], mod - 2);
    for (ll i = N - 1; i >= 1; i--) ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
}
ll ncr (ll n, ll r) {
    if (n < r) return 0;   return (((fact[n] * ifact[n - r]) % mod) * ifact[r]) % mod;
}
signed main()
{
	int test_case; scanf("%d", &test_case);
	factorial(nax);
	for (int test = 1; test <= test_case; test++)
	{
	    ll n, m; scanf("%lld %lld", &n, &m);
	    ll ans = 0;
	    ll choose = ncr(n, m);
	    for (ll i = 0LL; i < m; i++) {
	    	ll left = m - i;
	    	ll tmp = ncr(n - m, left);
	    	ll tmp2 = ncr(m, i); tmp *= tmp2; tmp %= mod;
	    	tmp *= choose; tmp %= mod;
	    	ans += tmp; ans %= mod;
	    }
	    cout << ans << '\n';
	}
	return 0;
}