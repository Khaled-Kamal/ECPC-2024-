#include <iostream>

using namespace std;

int main() {
    long long n, x;
    int h, m, s;
    
    
    cin >> n >> x >> h >> m >> s;
    
    long long total_seconds = h * 3600LL + m * 60LL + s;
    
    long long fallen_sand = x * total_seconds;
    
    long long remaining_sand = n - fallen_sand;
    
    if (remaining_sand < 0) {
        remaining_sand = 0;
    }
    
    cout << remaining_sand << endl;
    
    return 0;
}
