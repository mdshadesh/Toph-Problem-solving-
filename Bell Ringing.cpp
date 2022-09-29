#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef vector<int> vi;

vector<vi> permutations(int n)
{
    if (n == 1) return vector<vi> (1, vi(1, 1));
    vector<vi> nxt = permutations(n-1);

    vector<vi> r;
    bool d = false;
    for (vi &o : nxt)
    {
        if (!d) o.push_back(n);
        else o.insert(o.begin(), n);
        r.push_back(o);

        int c = d? 0:n-1;
        for (auto i = 0; i < n-1; i++)
        {
            int p = c + (d? 1:-1);
            swap(o[c], o[p]);
            c = p;
            r.push_back(o);
        }
        d = !d;
    }
    return r;
}

int main()
{
    int N;
    cin >> N;

    vector<vi> R = permutations(N);
    for (vi &o : R)
    {
        for (auto i = 0; i < N-1; i++) cout << o[i] << " ";
        cout << o.back() << endl;
    }
    return 0;
}