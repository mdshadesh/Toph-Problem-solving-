#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);

    int tt;
    cin>>tt;
    while(tt--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>a(n+1,vector<ll>(m+1));
        vector<vector<ll>>row(n+1,vector<ll>(m+1));
        vector<vector<ll>>col(m+1,vector<ll>(n+1));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                cin>>a[i][j];
                row[i][j]=a[i][j]+row[i][j-1];
                col[j][i]=a[i][j]+col[j][i-1];
            }
        if(n==1)
        {
            cout<<row[1][m]<<'\n';
            continue;
        }
        if(m==1)
        {
            cout<<col[1][n]<<'\n';
            continue;
        }
        ll rd=row[1][m]+col[m][n]-a[1][m];
        ll dr=row[n][m]+col[1][n]-a[n][1];
        ll ans=max(rd,dr);

        rd=row[1][m]+col[m][n]-a[1][m]+a[2][m-1];
        dr=row[n][m]+col[1][n]-a[n][1]+a[n-1][2];
        ans=max(ans,max(rd,dr));

        rd=row[1][m]+col[m-1][n]-a[1][m-1]+a[n][m];
        dr=row[n-1][m]+col[1][n]-a[n-1][1]+a[n][m];
        ans=max(ans,max(rd,dr));

        rd=row[2][m]+col[m][n]-a[2][m]-a[1][m]-a[2][1]+a[1][1];
        dr=row[n][m]+col[2][n]-a[n][1]-a[n][2]-a[1][2]+a[1][1];
        ans=max(ans,max(rd,dr));

        cout<<ans<<'\n';
    }
}