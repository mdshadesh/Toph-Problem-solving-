#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef APURBA
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 2e5 +5;
typedef pair<int,int> pii;

int rnk[N];
int parent[N];


void make_set(int n)
{
    for(int x=0; x<n; x++)
    {
        rnk[x]=0;
        parent[x]=x;
    }
}
int find_set(int x)
{
    if(parent[x]!=x)
    {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}
bool Union(int u,int v)
{
    int p= find_set(u),q=find_set(v);
    if(p==q)
        return 0;
    if( rnk[p] > rnk[q])
    {
        parent[q]= p;
    }
    else
    {
        parent[p]= q;
        if(rnk[p]==rnk[q])
        {
            rnk[q] +=1;
        }
    }
    return 1;
}

class Edge
{
public:
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
    bool operator<(Edge const& other)
    {
        return weight < other.weight;
    }
};

vector<Edge>edges;
int n;
inline void add_edge(int u, int v, int w)
{
    edges.push_back({u,v,w});
}
ll kruskal()
{
    ll cost = 0;
    make_set(n);
    sort(edges.rbegin(),edges.rend());
    for(int i=0; i<edges.size(); i++)
    {
        if(Union(edges[i].u,edges[i].v ))
            cost+=(ll)edges[i].weight;
    }
    return cost;
}


int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        edges.clear();
        for(int i=0; i<n; i++)
        {
            if(i%2 || i==n-1)
            {
                for(int j=0; j<18; j++)
                {
                    if((i&(1<<j)))
                    {
                        add_edge(i,i^(1<<j), i^(1<<j));
                    }
                }
            }
        }
        cout<<kruskal()<<"\n";
    }
    return 0;
}