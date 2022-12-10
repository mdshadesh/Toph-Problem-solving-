#include <bits/stdc++.h>
#define pb push_back
#define f first
#define sc second
using namespace std;
typedef long long int ll;
typedef string str;
void solve(){
    int n; cin >> n;
    vector<ll> v(n);
    for(ll &x: v) cin >> x;

    ll mx = 0, s = 0, ans = v[0];
    
    for(int i = 0; i < n; i++){
        s+=v[i];
        mx = max(mx, 0LL);
        ans = max(ans, s+mx);
        mx+=v[i];
    }

    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T; while(T--) solve();
}