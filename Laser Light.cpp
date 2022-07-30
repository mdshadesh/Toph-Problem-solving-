#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, x, y, ans[4] = {0};

    scanf("%d", &T);

    while(T--) {
        scanf("%d%d", &x, &y);

        if(x == 0 && y == 0) {
            ans[0]++, ans[1]++, ans[2]++, ans[3]++;
        } else if((x < 0 && y > 0 || x > 0 && y < 0) && abs(x) == abs(y)) {
            ans[0]++;
        } else if(x == 0 && y) {
            ans[1]++;
        } else if(y == 0 && x) {
            ans[2]++;
        } else if((x > 0 && y > 0 || x < 0 && y < 0) && abs(x) == abs(y)) {
            ans[3]++;
        }
    }

    int c = ans[0];

    for(int i = 1; i < 4; i++) {
        if(c < ans[i]) {
            c = ans[i];
        }
    }

    printf("%d\n", c);

    return 0;
}