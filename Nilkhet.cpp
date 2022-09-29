#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<long long>;
using db = double;
#define pb push_back

const long long mxn = 106 + 2;
const long long mxm = mxn * 2 * 6;
const long long MXL = 10000000000000;

using Flow = long long;
using Cost = long long;

struct Flownet
{
#define fore(i,e,x) for(long long i,e=fe[x]; i=ev[e],e; e=ne[e])
    long long n,m,fe[mxn],ne[mxm],ev[mxm];
    Flow f[mxm];
    Cost c[mxm];
    void clear(long long n)
    {
        this->n = n;
        fill(fe, fe + n + 1, 0);
        m = 1;
    }
    void add_(long long x, long long y, Flow F, Cost C)
    {
        ne[++m] = fe[x];
        fe[x] = m;
        ev[m] = y;
        f[m]=F;
        c[m]=C;
    }
    void add1(long long x, long long y, Flow F, Cost C)
    {
        add_(x, y, F, C);
        add_(y, x, 0, -C);
    }
    Cost d[mxn];
    bool inq[mxn];
    long long p[mxn];
    void spfa(long long S)
    {
        fill(d, d + n + 1, MXL);
        d[S] = 0;
        for (deque<long long> q = {S}; !q.empty(); )
        {
            long long x = q.front();
            q.pop_front(), inq[x] = false;
            fore(i,e,x) if (f[e] && d[i] > d[x] + c[e])
            {
                d[i] = d[x] + c[e], p[i] = e;
                if (!inq[i])
                    q.pb(i), inq[i] = true;
            }
        }
    }
    Cost mcmf(long long S, long long T)
    {
        Cost cost = 0;
        while (spfa(S), d[T] < MXL)
        {
            Flow t = MXL;
            for (long long i = T; i != S; i = ev[p[i] ^ 1])
                t = min(t, f[p[i]]);
            for (long long i = T; i != S; i = ev[p[i] ^ 1])
                f[p[i]] -= t, f[p[i] ^ 1] += t;
            cost += d[T] * t;
        }
        return cost;
    }
} G;

long long n, k;
long long a[mxn];
long long c[mxn];
long long r[mxn];
long long last[mxn];
long long S, T, m;

void addne(long long x, long long y, Flow F, Cost C)   // C <= 0
{
    G.add1(y, x, F, -C);
    G.add1(S, y, F, 0);
    G.add1(x, T, F, 0);
}

int main()
{
    int tc;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>tc;
    while(tc--)
    {
        memset(last,0,sizeof(last));
        cin >> n >> m >> k;
        S = n + 2;
        T = n + 3;
        for (long long i = 1; i <= k; ++i)
            cin >> c[i];
        for (long long i = 1; i <= k; ++i)
            cin >> r[i];

        for (long long i = 1; i <= n; ++i)
            cin >> a[i];


        G.clear(T);

        for (long long i = 1; i <= n; ++i)
            G.add1(i, i + 1, m - 1, 0);

        long long ans = 0;

        for (long long i = 1; i <= n; ++i)
        {
            if (last[a[i]])
                addne(i, last[a[i]], 1, -c[a[i]]+r[a[i]]);
            else
                ans += c[a[i]]-r[a[i]];
            last[a[i]] = i + 1;
        }

        ans += G.mcmf(S, T);
        //cout<<ans<<'\n';
        double lo=0,hi=100,mid,res;
        for(int gg=0; gg<1000; gg++)
        {
            mid=(lo+hi)/2.0;
            long double rent=0;
            for(int i=1;i<=n;i++){
                rent+=mid*c[a[i]]/100.0;
            }
            if(rent>=ans){
                hi=mid;
                res=mid;
            }
            else lo=mid;

        }
        //cout<<c[37]<<' '<<c[37]-r[37]<<'\n'<<c[50]<<' '<<c[50]-r[50]<<'\n';

        cout << fixed<<setprecision(10)<<res << endl;
    }

    return 0;
}