
#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i] >= 80)
        {
            count++;
        }
    }
    cout<<count<<endl;
}