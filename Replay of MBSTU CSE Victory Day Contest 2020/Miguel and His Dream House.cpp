#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


int n;
struct segtree {
    static const int maxn = 1e5 + 5;
    ll tree[maxn << 2] = {0};
    int tc[maxn << 2];
    void build(ll arr[], int node = 1, int l = 1, int r = n) {
        if (l == r) {tree[node] = arr[l]; tc[node] = 1; return; }
        int mid = (l + r) >> 1;
        build(arr, node << 1, l, mid);
        build(arr, node << 1 | 1, mid + 1, r);
        tree[node] = (tree[node << 1] ^ tree[node << 1 | 1]);
        tc[node] = (tc[node << 1] + tc[node << 1 | 1]);
    }
    void update(int pos, ll v, int node = 1, int l = 1, int r = n) {
        if (r < pos || l > pos) return;
        if (pos == l && pos == r) {
            tree[node] = v;
            return;
        } int mid = (l + r) >> 1;
        update(pos, v, node << 1, l, mid);
        update(pos, v, node << 1 | 1, mid + 1, r);
        tree[node] = (tree[node << 1] ^ tree[node << 1 | 1]);
        tc[node] = (tc[node << 1] + tc[node << 1 | 1]);
    }
    void dlt(int pos, int node = 1, int l = 1, int r = n) {
        if (r < pos || l > pos) return;
        if (pos == l && pos == r) {
            tree[node] = 0;
            tc[node] = 0;
            return;
        } int mid = (l + r) >> 1;
        dlt(pos, node << 1, l, mid);
        dlt(pos, node << 1 | 1, mid + 1, r);
        tree[node] = (tree[node << 1] ^ tree[node << 1 | 1]);
        tc[node] = (tc[node << 1] + tc[node << 1 | 1]);
    }
    ll query(int i, int j, int node = 1, int l = 1, int r = n) {
        if (r < i || l > j) return 0;
        if (i <= l && r <= j) {
            return tree[node];
        } int mid = ( l + r) >> 1;
        return (query(i, j, node << 1, l, mid) ^
                query(i, j, node << 1 | 1, mid + 1, r));
    }
    int kth(int pos, int node = 1, int l = 1, int r = n) {
        if (l == r)return l;
        int mid = (l + r) >> 1;
        if (tc[node << 1] >= pos)return kth(pos, node << 1, l, mid);
        else return kth(pos - tc[node << 1], node << 1 | 1, mid + 1, r);
    }
} t;

const int mx = 1e5 + 5;
const int mxx = 1e6 + 5;
ll val[mxx];
ll arr[mx];
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    for (int i = 1; i < mxx; i++)val[i] = rng();
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] = val[arr[i]];
    } t.build(arr);
    while (q--) {
        int ty, l, r;
        cin >> ty;
        if (ty == 1) {
            cin >> l >> r;
            l = t.kth(l);
            t.update(l, val[r]);
        } else if (ty == 2) {
            cin >> l;
            l = t.kth(l);
            t.dlt(l);
        } else {
            cin >> l >> r;
            l = t.kth(l);
            r = t.kth(r);
            ll va = t.query(l, r);
            cout << (va == 0 ? "Happy" : "Unhappy") << endl;
        }
    }
    return 0;
}