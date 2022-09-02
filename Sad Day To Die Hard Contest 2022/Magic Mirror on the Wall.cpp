#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main()
{    
    int t;
    cin >> t;
    while(t--)
    {
      double x1,y1,x2,y2;
      cin >> x1 >> y1 >> x2 >> y2 ;
    
      double ans;
      ans=y1/(y1+y2);
      ans=ans*(x2-x1);
     printf("%0.5lf 0\n",ans+x1);
    }
    
}