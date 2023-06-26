#include<bits/stdc++.h>
using namespace std;

int cnt[10000050];
bool mark[10000050];

void siv(int n) {
    int l = sqrt(n * 1.0) + 2; 
    int i, j;
    mark[0] = 1;
    mark[1] = 1;
    for (i = 4; i <= n; i += 2) {
        mark[i] = 1;
    }

    for (i = 3; i <= l; i += 2) {
        for (j = i * i; j <= n; j += i * 2) {
            mark[j] = 1;
        }
    }
    int c;
    for (i = 0, c = 0; i <= n; i++) {
        if (mark[i] == 0) c++;
        cnt[i] = c;
    }
    return;
}

int main() {
    int t;
    siv(10000050);
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << cnt[n - 1] << endl;
    }
}
