#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, s;
    scanf("%d %d", &a, &b);
    if(a==b) 
    {
        s=a;
    }
    else if(a>b) 
    {
        s=b;
    }
    else
    { 
        s=a; 
    }
    printf("%d\n", 2*s-1);
    return 0;
}