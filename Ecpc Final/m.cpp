#include <bits/stdc++.h>

using namespace std;
#define int long long

struct DSU {
  vector<int> par, sz;
  int ans;

  void init(int n) {
    ans = 0;
    par.assign(n, {});
    sz.assign(n, 1);
    iota(par.begin(), par.end(), 0);
  }

  int find(int u) {
    if (u == par[u])return u;
    return par[u] = find(par[u]);
  }

  int val(int s) { return s * (s - 1) / 2; }

  void merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))return;
    ans -= val(sz[u]) + val(sz[v]);
    par[u] = v;
    sz[v] += sz[u];
    ans += val(sz[v]);
  }

};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int &x: a)cin >> x;
  vector<pair<int, int>> vals;
  for (int i = 0; i + 1 < n; ++i) {
    int dif = a[i] - a[i + 1];
    vals.emplace_back(dif, i);
  }
  vector<pair<int, int>> queries(q);
  for (int i = 0, x; i < q; ++i) {
    cin >> x;
    queries[i] = {x, i};
  }
  DSU dsu;
  dsu.init(n);
  vector<int> ans(q);
  sort(queries.rbegin(), queries.rend());
  sort(vals.rbegin(), vals.rend());
  while (queries.size()) {

    auto [xq, iq] = queries.back();
    queries.pop_back();

    while (vals.size()) {
      auto [x, i] = vals.back();
      if (x > xq)break;
      dsu.merge(i, i + 1);
      vals.pop_back();
    }
    ans[iq] = dsu.ans;

  }
  for (int &x: ans) {
    cout << x << ' ';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    solve(), cout << '\n';
  }
}