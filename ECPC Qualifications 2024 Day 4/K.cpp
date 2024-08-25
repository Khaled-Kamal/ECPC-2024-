
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] += x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        if (L >= R) { return 0; }
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i] %= MOD;
    }
    vector<int64_t> P2(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        P2[i] = P2[i - 1] * 2 % MOD;
    }
    set<int64_t> S(a.begin(), a.end());
    map<int64_t, int> mp;
    for (int64_t x : S) {
        mp[x] = (int)mp.size();
    }
    int m = (int)mp.size();
    segment_tree<int64_t> b(m, 0, [&](int64_t x, int64_t y) { return (x + y) % MOD; });
    segment_tree<int64_t> c(m, 0, [&](int64_t x, int64_t y) { return (x + y) % MOD; });
    for (int i = 0; i < n; ++i) {
        c.update(mp[a[i]], P2[n - i - 1]);
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        c.update(mp[a[i]], (MOD - P2[n - i - 1]));
        //plus
        {
            int64_t l = b.query(0, mp[a[i]]);
            int64_t r = c.query(0, mp[a[i]]);
            ans += l * P2[n - i - 1] % MOD * a[i] % MOD;
            ans %= MOD;
            ans += r * P2[i] % MOD * a[i] % MOD;
            ans %= MOD;
        }
        //minus
        {
            int64_t l = b.query(mp[a[i]] + 1, m);
            int64_t r = c.query(mp[a[i]] + 1, m);
            ans += l * P2[n - i - 1] % MOD * (MOD - a[i]) % MOD;
            ans %= MOD;
            ans += r * P2[i] % MOD * (MOD - a[i]) % MOD;
            ans %= MOD;
        }
        b.update(mp[a[i]], P2[i]);
    }
    cout << ans;
}
