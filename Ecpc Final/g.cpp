#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int add(int a, int b) { return (a + b + 2 * mod) % mod; }

int mul(int a, int b) { return (a * b) % mod; }

int inv(int a) {
    return a <= 1 ? a : mod - mul(mod / a, inv(mod % a));
}

#define ll long long
#define vl vector<ll>
#define rep(aa, bb, cc) for(int aa = bb; aa < cc;aa++)
#define sz(a) (int)a.size()
typedef complex<double> C;
typedef vector<double> vd;

void fft(vector<C> &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vl rev(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            rep(j, 0, k) {
                // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
                auto x = (double *) &rt[j + k], y = (double *) &a[i + j + k];        /// exclude-line
                C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);           /// exclude-line
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
}

template<int M>
vl convMod(const vl &a, const vl &b) {
    if (a.empty() || b.empty()) return {};
    vl res(sz(a) + sz(b) - 1);
    int B = 32 - __builtin_clz(sz(res)), n = 1 << B, cut = (int) sqrt(M);
    vector<C> L(n), R(n), outs(n), outl(n);
    rep(i, 0, sz(a)) L[i] = C((int) a[i] / cut, (int) a[i] % cut);
    rep(i, 0, sz(b)) R[i] = C((int) b[i] / cut, (int) b[i] % cut);
    fft(L), fft(R);
    rep(i, 0, n) {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    rep(i, 0, sz(res)) {
        ll av = (ll) (real(outl[i]) + .5), cv = (ll) (imag(outs[i]) + .5);
        ll bv = (ll) (imag(outl[i]) + .5) + (ll) (real(outs[i]) + .5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s += '#';
    int tot = 26 * (n + 1), one = tot;
    vector<vector<int>> p;
    for (int i = 1, c = 1; i <= n; ++i) {
        if (s[i] == s[i - 1]) c++;
        else p.push_back({1, mul(c + 1, inv(tot))}), one -= c + 1, c = 1;
    }
    while (one--) p.push_back({1, inv(tot)});
    while (p.size() > 1) {
        vector<vl> nxt;
        for (int i = 0; i < p.size() - 1; i += 2)
            nxt.push_back(convMod<mod>(p[i], p[i + 1]));
        if (p.size() & 1) nxt.push_back(p.back());
        swap(p, nxt);
    }

    auto &v = p[0];
    v.push_back(0);
    int fact[v.size()];
    fact[0] = 1;
    for (int i = 1; i < v.size(); ++i) fact[i] = mul(fact[i - 1], i);
    int ans = 0, prev = 0;
    for (int i = 2; i < v.size(); ++i) {
        int c = add(1, -mul(v[i], fact[i]));
        c = add(c, -prev);
        ans = add(ans, mul(c, i));
        prev = add(prev, c);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
//	cin >> tc;
    while (tc--) {
        solve();
    }
}