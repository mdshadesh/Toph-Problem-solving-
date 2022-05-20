#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    string s;
    getchar();
    getline(cin,s);

    int len = s.size();
    for(int i=0;i<len;i++){
        if(s[i] == ' ')
            continue;
        int p = s[i];
        int q = p - n;
        if(q < 97){
            int d = 97 - q;
            q = 123 - d;
        }
        s[i] = q;
    }
    cout<<s ;
    return 0;
}