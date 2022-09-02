#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c, d, hit = 1, i, dis[10], tmp;
    cin>>a>>b>>c>>d;

    dis[0] = a*b;
    dis[1] = a*c;
    dis[2] = a*d;
    dis[3] = b*c;
    dis[4] = b*d;
    dis[5] = c*d;

    for(i=0; i<6; i++) {
        if(hit == 1) {
            tmp = dis[i];
            hit = 0;
        }
        else {
            if(tmp < dis[i]) {
                tmp = dis[i];
            }
        }
    }
    cout<<tmp<<"\n";
    return 0;
}