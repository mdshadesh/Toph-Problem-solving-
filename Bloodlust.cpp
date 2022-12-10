#include <bits/stdc++.h>
#define ll long long int

using namespace std;

double pi=2*acos(0.0);

int main(){

    int t;
    cin>>t;
    for(int tc=0;tc<t;tc++){
        double n;

        cin>>n;

        double res=2*n*cos(pi/5.00);

        printf("%.5f\n",res);
    }
}