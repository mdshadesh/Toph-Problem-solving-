#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, c[4]={0};
    char a;
    cin >> n;
    while(n--)
    {
        cin >> a;
        if(a == 'c')    c[0]++;
        else if(a == 'o' && c[1]<c[0])   c[1]++;
        else if(a == 'd' && c[2]<c[1])   c[2]++;
        else if(a == 'e'&& c[3]<c[2])   c[3]++;
    }
    sort(c,c+4);
    cout << c[0] << endl;
    return 0;
}