#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector <int> g[maxn];
int sub[maxn];
long long dp[maxn], fn[maxn], total[maxn];
long long ans;
int n;

void subtree(int x, int p) {
    sub[x] = 1;
    long long sum = 0;
    for(auto i : g[x]) {
        if(i == p) continue;
        subtree(i, x);
        sub[x] += sub[i];
        sum += total[i] + sub[i];
    }
    total[x] = sum;
    vector <long long> cands;
    for(int i : g[x]) {
        if(i == p) continue;
        cands.push_back(fn[i] - total[i] - sub[i]);
    }
    sort(cands.begin(), cands.end());
    if(cands.size() == 0) {
        fn[x] = dp[x] = 0;
    } else if (cands.size() == 1) {
        fn[x] = dp[x] = cands[0] + sum;
    } else {
        fn[x] = cands[0] + sum;
        dp[x] = cands[0] + cands[1] + sum;
    }
}

void dfs(int x, int p, long long dist) {
    for(auto i : g[x]) {
        if(i == p) continue;
        dfs(i, x, dist + total[x] - total[i] - sub[i] + n - sub[i]);
    }
    // cout << x << " " << dist << endl;
    ans = min(ans, dist + fn[x]);
    ans = min(ans, dist + dp[x]);
}


int main() {
    int t, cs = 0;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1; i < n; i++) {
            int p, q;
            cin >> p >> q;
            g[p].push_back(q);
            g[q].push_back(p);
        }
        ans = LLONG_MAX;
        subtree(1, 0);
        dfs(1, 0, 0);
        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0;
}