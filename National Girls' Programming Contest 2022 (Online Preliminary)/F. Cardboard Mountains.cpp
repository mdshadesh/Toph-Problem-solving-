#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define boost_ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int main() {
    boost_;
    int t;
    cin >> t;
    while(t--) {
        ll n, X, x, y, lx = 0, ly = 0;
        cin >> n >> X;
        map<ll, ll> mp;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            mp[x] = max(mp[x], y);
        }
        double ans = 0;
        for(auto it : mp) {
            x = it.first, y = it.second;
            double tempx = (lx * y + ly * x) / (double) (ly + y);
            double tempy = ((tempx - x) * ly) / (double) (lx - x);
            ans += 0.5 * (x - lx) * (ly + y) - 0.5 * (x - lx) * tempy;
            lx = x, ly = y;
        }
        ans += 0.5 * (X - lx) * ly;
        cout << setprecision(10) << fixed << ans << endl;
    }
}