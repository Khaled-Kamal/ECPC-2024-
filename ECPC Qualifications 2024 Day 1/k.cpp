#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (r1 < r2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    
    long double d = sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    
    if (d >= r1 + r2 || (d == 0 && r1 == r2) || d < r1 - r2) {
        cout << -1;
        return 0;
    }
    
    long double p1 = r1 * r1 * acos((d * d + r1 * r1 - r2 * r2) / (2. * d * r1));
    long double p2 = r2 * r2 * acos((d * d + r2 * r2 - r1 * r1) / (2. * d * r2));
    long double p3 = 0.5 * sqrtl((d + r1 + r2) * (-d + r1 + r2) * (d - r1 + r2) * (d + r1 - r2));
    long double x = p1 + p2 - p3; 

    long double pi = 3.14159265358979323846;
    long double mx = pi * r1 * r1;
    
    cout << setprecision(20) << mx - x;
    return 0;
}