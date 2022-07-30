#include <bits/stdc++.h>
using namespace std;

int perfectSquare(string s)
{
    int n = s.size();
    int ans = -1;
    string num;
    for (int i = 1; i < (1 << n); i++) {
        string str = "";

        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                str += s[j];
            }
        }
        if (str[0] != '0') {

            int temp = 0;
            for (int j = 0; j < str.size(); j++)
                temp = temp * 10 + (int)(str[j] - '0');

            int k = sqrt(temp);
            if (k * k == temp) {
                if (ans < (int)str.size()) {
                    ans = (int)str.size();
                    num = str;
                }
            }
        }
    }

    if (ans == -1)
        return ans;
    else {
        return n - ans;
    }
}
int main()
{
     int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<perfectSquare(s)<<endl;
    }
    return 0;
}