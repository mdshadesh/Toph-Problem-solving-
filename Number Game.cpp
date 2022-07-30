#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1)
int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        int n,montu=0,jhontu=0,draw=0;
        cin >> n;
        while(n--)
        {
            ll a,b;
            cin >> a >> b;
            if(a==b)
            {
                draw++;
                continue;
            }
            while(a!=1 && b!=1)
            {
                if(a%2==0)
                    a/=2;
                else
                    a = a*3 + 1;
                if(b%2==0)
                    b/=2;
                else
                    b = b*3 + 1;
                if(a==b)
                    break;
            }
            if(a==1)
                montu++;
            else if(b==1)
                jhontu++;
            else
                draw++;
        }

        printf("Game No %d: Montu %d, Jhontu %d, Draw %d\n",i,montu,jhontu,draw);
    }
    return 0;
}