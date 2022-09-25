#include <bits/stdc++.h>
#define MAXVAL 100
using namespace std;
typedef long long ll;

ll cnt[10009][MAXVAL+2], n, v[10009], ans[10009];

void gen() {
    for(int i = 0; i < n; ++i) {
        cnt[i][v[i]]++;
        if(i != 0)
            for(int j = 0; j <= MAXVAL; ++j)
                cnt[i][j] += cnt[i-1][j];
    }
    for(int i = 0; i < n; ++i)
        for(int j = 1; j <= MAXVAL; ++j)
            cnt[i][j] += cnt[i][j-1];
}

ll Bigger(int r, int val) {
    ll ret = 0;
    if(r)
        ret = cnt[r-1][MAXVAL] - cnt[r-1][val];
    return ret;
}

ll Smaller(int l, int val) {
    ll ret = 0;
    if(val)
        ret = cnt[n-1][val-1] - cnt[l][val-1];
    return ret;
}

void genInversion() {
    for(int i = 0; i < n; ++i)
        ans[i] = cnt[n-1][v[i]-1] - cnt[i][v[i]-1] + (i > 0 ? ans[i-1]:0);
}

ll getAns(int pos) {
    return ans[pos] - (pos ? ans[pos-1]:0);
}

ll swapQuery(int l, int r) {
    if(l == r or v[l] == v[r]) return ans[n-1];
    
    ll ret = ans[n-1] - getAns(l) - getAns(r);

    ret -= Bigger(l, v[l]);
    ret -= Bigger(r, v[r]);
    
    ret += Smaller(r, v[l]);
    ret += Bigger(r, v[l]);
    
    ret += Smaller(l, v[r]);
    ret += Bigger(l, v[r]);

    return ret + 1;
}

ll eraseQuery(int l, int r) {
    if(l > r) swap(l, r);
    ll ret = ans[n-1] - (ans[r] - (l > 0 ? ans[l-1]:0));

    ll x = 0;
    for(int i = 0; i <= MAXVAL; ++i) {
        x = (cnt[r][i] - (l > 0 ? cnt[l-1][i]:0)) - (i > 0 ? (cnt[r][i-1] - (l > 0 ? cnt[l-1][i-1]:0)):0);
        if(x > 0)
            ret -= Bigger(l, i)*x;
    }
    return ret;
}

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i) scanf("%lld", &v[i]);

    gen();
    genInversion();

    int q, l, r, typ;
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d%d", &typ, &l, &r);
        if(typ == 0)
            printf("%lld\n", swapQuery(l, r));
        else
            printf("%lld\n", eraseQuery(l, r));
    }

    return 0;
}