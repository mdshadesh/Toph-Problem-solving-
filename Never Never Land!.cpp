#include<bits/stdc++.h>
using namespace std;
int main()
{

    int i,c=0;
    string st;
    cin >> st;
    for(i=0; i<st.size(); i++)if(st[i]=='n')
		c++;
    cout << c << "\n";

   return 0;
}