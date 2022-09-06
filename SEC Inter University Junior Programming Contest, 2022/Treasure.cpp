#include <iostream> 
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    bool successful = N < 4 ? true : false;
    while (M--) 
    {
        string text;
        cin >> text;
        if (text == "out")
            N--;
        else
            N++;
            
        if (N < 4)
            successful = true;
    }
    if (successful)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0; 
}