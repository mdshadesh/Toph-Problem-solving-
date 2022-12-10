#include<bits/stdc++.h>
using namespace std;

int main()
{
int a,b,n,i,c=0;
cin >> n;
for(i=0; i<n; i++)
{
    cin >> a;
    if(!(a&1))c++;
}
cout << c << "\n";


return 0;
}