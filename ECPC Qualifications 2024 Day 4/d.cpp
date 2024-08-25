#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tt, tc;

const int N = 1e5 + 9;
ll tree[N << 2], lazy[N << 2], count_bits[30][N << 2];
ll a[N];
int n;

void propagate_lazy(int p, int sz) {
    if (!lazy[p]) return;
    for (int j = 29; j >= 0; --j) {
        if ((1LL << j) & lazy[p]) {
            tree[p] -= (1LL << j) * count_bits[j][p];
            count_bits[j][p] = sz - count_bits[j][p];
            tree[p] += (1LL << j) * count_bits[j][p];
        }
    }
    if (sz > 1) {
        lazy[p << 1] ^= lazy[p];
        lazy[p << 1 | 1] ^= lazy[p];
    }
    lazy[p] = 0;
}

void build(int p = 1, int l = 1, int r = n) {
    if (l == r) {
        tree[p] = a[l];
        for (int j = 29; j >= 0; --j) {
            if ((1LL << j) & a[l]) count_bits[j][p] += 1;
        }
        return;
    }
    int m = (l + r) / 2;
    build(p << 1, l, m);
    build(p << 1 | 1, m + 1, r);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
    for (int j = 29; j >= 0; --j) {
        count_bits[j][p] = count_bits[j][p << 1] + count_bits[j][p << 1 | 1];
    }
}

void update(int L, int R, ll x, int p = 1, int l = 1, int r = n) {
    propagate_lazy(p, r - l + 1);
    if (L > r || l > R) return;
    if (L <= l && r <= R) {
        lazy[p] = x;
        propagate_lazy(p, r - l + 1);
        return;
    }
    int m = (l + r) / 2;
    update(L, R, x, p << 1, l, m);
    update(L, R, x, p << 1 | 1, m + 1, r);

    tree[p] = tree[p << 1] + tree[p << 1 | 1];
    for (int j = 29; j >= 0; --j) {
        count_bits[j][p] = count_bits[j][p << 1] + count_bits[j][p << 1 | 1];
    }
}

ll query(int L, int R, int p = 1, int l = 1, int r = n) {
    propagate_lazy(p, r - l + 1);
    if (L > r || l > R) return 0;
    if (L <= l && r <= R) return tree[p];
    int m = (l + r) / 2;
    return query(L, R, p << 1, l, m) + query(L, R, p << 1 | 1, m + 1, r);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    build();

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << "\n";
        } else {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            update(l, r, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    tt = 1, tc = 1; // cin >> tt;
    while (tt--) solve(), tc++;
}