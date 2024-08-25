#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    vector<int> A(n);  
    vector<int> D(n);  
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> D[i];
    }

    int hitCount = 0;

    for (int i = 0; i < n; ++i) {
        double timeToReach = static_cast<double>(D[i]) / v;
        if (A[i] >= timeToReach) {
            ++hitCount;
        }
    }

    cout << hitCount << endl;

    return 0;
}
