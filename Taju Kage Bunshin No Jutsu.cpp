#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 100;
const int LOG = 50;

struct Nd {
    int sum , l , r ;
}node[N*LOG] ;

int TotNode = 0;

int upd (int cn , int b , int e , int i , int val) {

    int cur = ++TotNode ;
    if (b == e) {
        node[cur].sum = node[cn].sum + val ;
        return cur ;
    }
    int mid = (b+e)/2 ;
    if (i <= mid) {
        node[cur].l = upd(node[cn].l , b , mid , i , val);
        node[cur].r = node[cn].r ;
    }
    else {
        node[cur].r = upd(node[cn].r , mid+1 , e , i , val) ;
        node[cur].l = node[cn].l ;
    }

    node[cur].sum = node[node[cur].l].sum + node[node[cur].r].sum ;
    return cur ;
}

int query (int cn , int b , int e , int i, int j) {
    if (b > j or e < i or !cn) return 0 ;
    if (b >= i and e <= j) {
        return node[cn].sum ;
    }
    int mid = (b+e)/2 ;
    return query(node[cn].l,b,mid,i,j) + query(node[cn].r,mid+1,e,i,j) ;
}

int main() {

    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n;
    vector<int> stk;
    stk.push_back(0);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        stk.push_back(upd(stk.back(), 1, 1e9, x, +1));
    }
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int v;
            cin >> v;
            stk.push_back(upd(stk.back(),1,1e9,v,+1));
        }
        else if(type == 2) {
            stk.pop_back();
        }
        else {
            int l, r, k;
            cin >> l >> r >> k;
            int lo = 1, hi = 1e9;
            while(hi > lo) {
                int mid = (hi+lo+1)/2;
                if(query(stk[r],1,1e9,mid,1e9)-query(stk[l-1],1,1e9,mid,1e9) < k) {
                    hi = mid-1;
                }
                else {
                    lo = mid;
                }
            }
            cout << lo << "\n";
        }
    }
    return 0;
}