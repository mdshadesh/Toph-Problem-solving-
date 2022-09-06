#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = (int)2e5+6;
#define pi acos(-1.0)

int main()
{
    int t;
    cin >> t;
    while(t--){
        double l;
        scanf("%lf", &l);
        double ans = pi * l * l;
        printf("%.6lf\n", ans);
    }

    return 0;
}