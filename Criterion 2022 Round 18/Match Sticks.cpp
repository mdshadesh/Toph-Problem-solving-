#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;

    while(scanf("%d", &n) != EOF) 
    {
        if((n - 2) % 3 == 0) 
           printf("Yes\n");
        else 
           printf("No\n");
    }
    return 0;
}