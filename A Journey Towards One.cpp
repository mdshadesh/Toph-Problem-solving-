#include<iostream>
using namespace std;
int counter = 0;
int ToOne(int n)
{
    if (n <= 1)
    {
        return counter;
    }
            if (n == 3)
            {
                counter = 2;
                return counter;
            }
            if (n % 2 == 0)
            {
                ToOne(n / 2);
                counter++;
            }
            else if (((n - 1) / 2) % 2 == 0)
            {
                ToOne(n - 1);
                counter++;
            }
            else
            {
                ToOne(n + 1);
                counter++;
            }
            return counter;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << ToOne(n) << endl;
        counter = 0;
    }
}