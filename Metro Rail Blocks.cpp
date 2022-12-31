#include <bits/stdc++.h>
using namespace std;

int arr[1000005];

int main()
{
    int n, num;
    cin>>n;
    int pos = 1, counter = 0;
    for(int i=0; i<n; ++i) 
    {
        cin>>num;
        arr[num] = 1;
        if(arr[pos]==1) 
        {
            for(int j=pos; j<=n; ++j) 
            {
                if(arr[j]==1) 
                {
                    ++counter;
                }
                else {
                    pos = j;
                    break;
                }
            }
        }
        cout<<counter<<endl;
    }
}