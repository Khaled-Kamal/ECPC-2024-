#include <bits/stdc++.h>

using namespace std;
#define double long double
struct point {
    double x, y;

    friend istream &operator>>(istream &in, point &p) {
        return in >> p.x >> p.y;
    }
};
void rotate(point &P, double ang) {
    P = {cosl(ang) * P.x - sinl(ang) * P.y, cosl(ang) * P.y + sinl(ang) * P.x};
}

const double pi = acos(-1), eps = 1e-9;

void Tc() {
    point A, B, C, t;
    int s;
    cin >> A >> B >> C >> t >> s;
    if (!s)
        swap(A, C);
    A.x -= B.x;
    C.x -= B.x;
    t.x -= B.x;
    A.y -= B.y;
    C.y -= B.y;
    t.y -= B.y;

    double rot = -atan2l(A.y, A.x);
    rotate(A, rot), rotate(C, rot), rotate(t, rot);

    double c = atan2l(C.y, C.x), orig = atan2l(t.y, t.x);

    if (c * orig > eps && abs(orig) * 2 + eps < pi) {
        cout << "YES\n";
        orig *= 180 / pi;
        c *= 180 / pi;
        cout << 2 * orig - c << '\n';
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int t = 1;

    cout << fixed << setprecision(9);
    cin >> t;

    while (t--) {
        Tc();
    }

    return 0;
}