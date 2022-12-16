#include<bits/stdc++.h>
using namespace std;
int tst;
double ab,ad,ang;
int main()
{
    cin>>tst;
    while(tst--)
    {
        cin>>ab>>ad>>ang;
        double bd=sqrt((ad*ad)+(ab*ab)-(2*cos((ang*acos(-1))/180.00)*ab*ad));
        double d=acos(((ad*ad)+(bd*bd)-(ab*ab))/(2*ad*bd));
        d=(acos(-1)-d);
        double ac=sqrt((ad*ad)+(bd*bd)-(2*cos(d)*ad*bd));
        printf("%.9lf\n",(ac*ac)+(ab*ab));
    }
    return 0;
}