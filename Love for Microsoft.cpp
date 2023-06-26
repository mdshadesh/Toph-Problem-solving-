#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string checkFondness(const string& username) {
    unordered_set<char> requiredChars{'m', 'i', 'c', 'r', 'o', 's', 'f', 't'};

    for (char c : username) {
        requiredChars.erase(c);
    }

    if (requiredChars.empty()) {
        return "We both love Microsoft!";
    } else {
        return "Only I love Microsoft!";
    }
}

int main() {
    string username;
    cin >> username;

    string result = checkFondness(username);
    cout << result << endl;

    return 0;
}
