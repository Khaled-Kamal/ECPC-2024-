#include <bits/stdc++.h>

#define el '\n'
#define Beevo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef long double ld;

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int LOG = 22;

struct SparseTable {
    vector<int> pre;
    vector<vector<int>> g;

    SparseTable(vector<int> &v) {
        int n = v.size();

        g.resize(n + 5);
        pre.resize(n + 5);

        for (int i = 0; i < n; i++)
            g[i].resize(LOG);

        pre[1] = 0;
        for (int i = 2; i <= n; i++)
            pre[i] = pre[i >> 1] + 1;

        for (int i = 0; i < n; i++)
            g[i][0] = v[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) - 1 < n; i++)
                g[i][k] = min(g[i][k - 1], g[i + (1 << (k - 1))][k - 1]);
        }
    }

    int query(int l, int r) {
        int d = r - l + 1, k = pre[d];

        return min(g[l][k], g[r - (1 << k) + 1][k]);
    }
};

struct SuffixArray {
    string S;
    vector<int> sa, lcp;

    SuffixArray(string &s, int lim = 256) {
        S = s;

        int n = s.size() + 1, k = 0, a, b;
        vector<int> x(s.begin(), s.end() + 1), y(n), ws(max(n, lim)), rank(n);

        sa = lcp = y, iota(sa.begin(), sa.end(), 0);

        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(y.begin(), y.end(), n - j);

            for (int i = 0; i < n; i++) {
                if (sa[i] >= j)
                    y[p++] = sa[i] - j;
            }

            fill(ws.begin(), ws.end(), 0);

            for (int i = 0; i < n; i++) ws[x[i]]++;
            for (int i = 1; i < lim; i++) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];

            swap(x, y), p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                a = sa[i - 1], b = sa[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }

        for (int i = 1; i < n; i++) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);
    }
};

void testCase() {
    int n;
    string s;
    cin >> n >> s;

    SuffixArray sa(s);

    vector<pair<int, int>> pre(n + 1, {-1, -1});

    for (int i = 1; i < sa.sa.size(); i++)
        pre[n - sa.sa[i]] = {i, sa.sa[i]};

    for (int i = n - 1; i >= 1; i--) {
        if (pre[i + 1].first < pre[i].first)
            pre[i] = pre[i + 1];
    }

    SparseTable st(sa.lcp), st2(sa.sa);

    for (int i = 1; i <= n; i++) {
        int l = pre[i].first + 1, r = sa.sa.size() - 1, m, sol = pre[i].first;
        while (l <= r) {
            m = (l + r) >> 1;

            int mn = st.query(pre[i].first + 1, m);

            if (mn >= i)
                sol = m, l = m + 1;
            else
                r = m - 1;
        }

        cout << st2.query(pre[i].first, sol) + 1 << ' ';
    }

    cout << el;
}

signed main() {
    Beevo

    int t = 1;
    cin >> t;

    while (t--)
        testCase();
}