#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, last, num, len[N], link[N], child[N][26], occ[N], xaucuoi[N], a[N];
int R[N][20];
string s;

void initTree()
{
    memset(child, 0, sizeof(child));
    memset(xaucuoi, 0, sizeof(xaucuoi));
    memset(occ, 0, sizeof(occ));
    len[0] = 0, len[1] = -1, link[0] = link[1] = 1;
    last = 0, num = 1;
}
int insert(int i, int id)
{
    int w = s[i] - 'a';
    while (i - len[last] - 1 < 0 || s[i - len[last] - 1] != s[i])
        last = link[last];
    if (child[last][w] == 0)
    {
        int temp = link[last];
        while (i - len[temp] - 1 < 0 || s[i - len[temp] - 1] != s[i])
            temp = link[temp];
        child[last][w] = ++num, len[num] = len[last] + 2;
        link[num] = (len[num] == 1 ? 0 : child[temp][w]);
    }
    last = child[last][w];
    occ[last] += (xaucuoi[last] != id), xaucuoi[last] = id;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        initTree();
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            for (int j = 0; j < s.size(); j++)
                insert(j, i);
        }
        fill(a, a + N, 0);
        for (int i = 2; i <= num; i++)
            a[occ[i]] = max(a[occ[i]], len[i]);
        //dung RMQ max
        for (int i = 1; i <= n; i++)
            R[i][0] = a[i];
        for (int k = 1; (1 << k) <= n; k++)
            for (int i = 1; i + (1 << (k - 1)) <= n; i++)
                R[i][k] = max(R[i][k - 1], R[i + (1 << (k - 1))][k - 1]);
        for (int i = 1, u, v; i <= m; i++)
        {
            cin >> u >> v;
            int k = log2(v - u + 1);
            cout << max(R[u][k], R[v - (1 << k) + 1][k]) << "\n";
        }
    }
    return 0;
}