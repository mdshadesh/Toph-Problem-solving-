#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;

    scanf("%d", &T);

    while(T--) {
        int n;

        scanf("%d", &n);

        if(n == 1971) {
            puts("Joy Bangla");
        } else if(n & 1) {
            puts("Joy");
        } else {
            puts("Bangla");
        }
    }

    return 0;
}