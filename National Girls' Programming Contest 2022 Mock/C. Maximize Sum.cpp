#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const LL INF =  1e18;
const int N = 1e4 +7;

LL dp[N][13][13];

LL A[N];
LL B[12];


LL calc(int n, int m, int K) {

    for(int i=0; i<=1+n; i++){
        for(int j=0; j<=1+m; j++){
            for(int k=0; k<=1+K; k++){
                dp[i][k][j] = -INF;
            }
        }
    }

    dp[0][K][0] = 0;
    for(int i=0; i<=n; i++){
        for(int k =K; k>=0; k--){
            for(int j=0; j<=m; j++){
                if(i==0 && k== K && j==0) continue;
                LL &ret = dp[i][k][j];
                LL pos = j + i- K + k; 
                if(j-1>=0)ret = max(ret, dp[i][k][j-1] + B[j]*pos);
                if(i-1>=0)ret = max(ret, dp[i-1][k][j] + A[i]*pos);
                if(i-1>=0)ret = max(ret, dp[i-1][k+1][j]);
            }
        }
    }

    LL ret = -1e18;
    for(int k=0; k<=K; k++)
        ret = max(ret , dp[n][k][m]);

    return ret;
}


void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);


    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    sort(b.rbegin(), b.rend());

    for(int i=1; i<=n; i++) A[i] = a[i-1];

    LL ans = -1e18;
    for(int i=0; i<=m; i++){
        vector<int> cur;
        for(int j=0; j<i; j++){
            cur.push_back(b[j]);
        }
        sort(cur.begin(), cur.end());
        for(int j=1; j<=cur.size(); j++) B[j] = cur[j-1];
        ans = max(ans, calc(n,i, k));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}