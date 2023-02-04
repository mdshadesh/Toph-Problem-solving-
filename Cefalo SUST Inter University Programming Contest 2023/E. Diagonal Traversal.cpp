#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;
        cout<<"Case "<<++ii<<": ";
        if(n>m) swap(n,m);
        if(n<=3){
            if(n==1 && m==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }

        ll chk=1;
        if((n==4 && (m<5 || (m-5)%8)) || (n==5 && (m<=9 || m%2)) || (n==6 && (m<=10 || m%2==0))) chk=0;
        if(chk) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}