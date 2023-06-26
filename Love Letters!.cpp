#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

int main() {
    int Tc;
    cin >> Tc;
    
    for (int testCase = 1; testCase <= Tc; testCase++) {
        int N;
        string S;
        cin >> N >> S;
        
        map<char, int> frequency;
        for (char ch : S) {
            frequency[ch]++;
        }
        
        map<char, int> result;
        for (auto it = frequency.begin(); it != frequency.end(); it++) {
            if (isPrime(it->second)) {
                result[it->first] = it->second;
            }
        }
        
        cout << "Case " << testCase << ":\n";
        
        if (result.empty()) {
            cout << "Love is painful !\n";
        } else {
            for (auto it = result.begin(); it != result.end(); it++) {
                cout << it->first << " = " << it->second << "\n";
            }
        }
    }
    
    return 0;
}
