#include<bits/stdc++.h>
using namespace std;
int k,id;
struct pt{
    double x,y;
}a[1000],b[100],ans[1000];

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return +1; // counter-clockwise
    if (v > 0) return -1; // clockwise
    return 0;
}

void convex_hull(){
    pt p0 = *min_element(a,a+k,[](pt a, pt b){
        return make_pair(a.y,a.x)<make_pair(b.y,b.x);
    });

    sort(a,a+k,[&p0](const pt& a, const pt& b){
        int o = orientation(p0,a,b);
        if(o == 0) return (p0.x-a.x)*(p0.x-a.x)+(p0.y-a.y)*(p0.y-a.y)<(p0.x-b.x)*(p0.x-b.x)+(p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });

    for(int i = 0;i < k;i++){
        while(id>1 && orientation(ans[id-2],ans[id-1],a[i])>=0) id--;
        ans[id++] = a[i];
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++) cin>>b[i].x>>b[i].y;
    for(i=0;i<m;i++){
        double X,Y;
        cin>>X>>Y;
        for(j=0;j<n;j++){
            a[k].x = (X+b[j].x)/2.0;
            a[k].y = (Y+b[j].y)/2.0;
            k++;
        }
    }
    convex_hull();
    cout<<id<<'\n';
    cout<<fixed<<setprecision(2);
    for(i=0;i<id;i++) cout<<ans[i].x<<' '<<ans[i].y<<'\n';
}