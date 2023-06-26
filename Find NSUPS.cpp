#include <iostream>

using namespace std;

int main() {
    int ls;
    cin >> ls;
    
    char s[1010];
    cin >> s;
    
    long long arr[5] = {0, 0, 0, 0, 0};
    
    for (int i = 0; i < ls; ++i) {
        if (s[i] == 'S') 
			arr[4] += arr[3];
        if (s[i] == 'P') 
			arr[3] += arr[2];
        if (s[i] == 'U') 
			arr[2] += arr[1];
        if (s[i] == 'S') 
			arr[1] += arr[0];
        if (s[i] == 'N') 
			arr[0]++;
    }
    
    cout << arr[4] << endl;
    
    return 0;
}
