#include <bits/stdc++.h>
using namespace std;

const int matrix_size = 2, mod = 998244353;

struct matrix {
    int mat[matrix_size][matrix_size] = {{1, 0}, {0, 1}};
    matrix friend operator *(const matrix &a, const matrix &b) {
        matrix c;
        for (int i = 0; i < matrix_size; i++) {
          for (int j = 0; j < matrix_size; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < matrix_size; k++) {
                  c.mat[i][j] += (1ll * a.mat[i][k] * b.mat[k][j]) % mod;
                  if (c.mat[i][j] >= mod) c.mat[i][j] -= mod;
              }
          }
        }
        return c;
    }
};

pair<int, int> fp(matrix b, long long p) {
    matrix r;
    while (p) {
        if (p & 1) r = r * b;
        b = b * b;
        p >>= 1;
    }
    return make_pair(r.mat[0][0], r.mat[0][1]);
}

void solve() {

    int n;
    long long k, sum = 0;
    cin >> n >> k;

    matrix base = {{{-2, 1}, {0, n - 2}}};
    auto [v, s] = fp(base, k);

    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < n; i++) {
        cout << ((((1ll * v * (a[i] % mod)) % mod + mod) % mod) + (((1ll * s * (sum % mod)) % mod + mod) % mod)) % mod << "\n";
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }

    return 0;
}
