#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pil = pair<int, ll>;
#define fi first
#define se second
#define print(x) cout<<"["<<(x)<<"]"
const pil INF = {-1, -1};
const int N = 12;
string a, b;
pil dp[N][N][N][2][2][2];
pil comb(pil x, pil y){
    if (x.fi == y.fi) return {x.fi, x.se + y.se};
    else if (x.fi > y.fi) return x;
    return y;
}
pil recur(int l, int i, int mx, bool lo, bool hi, bool ze){
    if (i == b.size()){
        return {l, 1};
    }
    if (dp[l][i][mx][lo][hi][ze] != INF)
        return dp[l][i][mx][lo][hi][ze];
    pil ret = INF;
    int d = (lo ? 0 : a[i] - '0'), u = (hi ? 9 : b[i] - '0');
    for (int j = d; j <= u; j++){
        bool lon = lo | (j > d);
        bool hin = hi | (j < u);
        bool zen = ze | (j != 0);
        ret = comb(ret, recur(l, i + 1, mx, lon, hin, zen));
        if (j > mx || (j == 0 && l == 0 && ze)) ret = comb(ret, recur(l + 1, i + 1, j, lon, hin, zen));
    }
    return dp[l][i][mx][lo][hi][ze] = ret;
}
void solve(int i){
    memset(dp, -1, sizeof dp);
    pil tmp = recur(0, 0, 0, 0, 0, 0);
    cout << "Case " << i << ": " << tmp.fi << " " << tmp.se << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> a >> b;
        while (a.size() < b.size())
            a = '0' + a;
        solve(i);
    }
}