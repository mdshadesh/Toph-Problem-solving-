#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int testCase = 0; testCase < T; testCase++) {
        int N, K;
        cin >> N >> K;

        int missingSlices = 0;
        for (int i = 0; i < N; i++) {
            int ai;
            cin >> ai;
            missingSlices += K - ai;
        }

        int newPizzas = ceil((double) missingSlices / K);
        cout << newPizzas << endl;
    }

    return 0;
}
