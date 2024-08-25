#include <bits/stdc++.h>

using namespace std;
#define int long long

const int M = 998244353;

int add(int a, int b) { return (a + b + 2 * M) % M; }

int mul(int a, int b) { return a * b % M; }

const int N = 3e6 + 5;
int fact[N], inv[N], invfact[N];

void init() {
    fact[0] = fact[1] = 1;
    inv[0] = inv[1] = 1;
    invfact[0] = invfact[1] = 1;
    for (int i = 2; i < N; ++i) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = M - mul(M / i, inv[M % i]);
        invfact[i] = mul(invfact[i - 1], inv[i]);
    }
}

int binpow(int n, int p) {
    int ret = 1, x = n;
    while (p) {
        if (p & 1) ret = mul(ret, x);
        x = mul(x, x), p >>= 1;
    }
    return ret;
}

void fft(vector<int> &a) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    int g = binpow(3, (M - 1) / n);
    for (int len = 2; len <= n; len <<= 1) {
        int w1 = binpow(g, n / len);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j], v = mul(w, a[i + j + len / 2]);
                a[i + j] = add(u, v);
                a[i + j + len / 2] = add(u, -v);
                w = mul(w, w1);
            }
        }
    }
}


vector<int> multiply(vector<int> &a, vector<int> &b) {
    vector fa(a), fb(b);
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa);
    fft(fb);
    for (int i = 0; i < n; ++i) fa[i] = mul(fa[i], fb[i]);
    fft(fa);
    reverse(fa.begin() + 1, fa.end());
    vector<int> res(n);
    int x = inv[n];
    for (int i = 0; i < n; ++i) res[i] = mul(fa[i], x);
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m+1), b(1, 1);
    for (int i = 0; i <= m; ++i)
        a[i] = invfact[i];
    while (n) {
        if (n&1) b = multiply(b, a);
        a = multiply(a, a), n >>= 1;
    }
    int q;
    cin >> q;
    while (q--) {
        int i;
        cin >> i;
        cout << mul(fact[i], b[i]) << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
        cout << '\n';
    }
    return 0;
}