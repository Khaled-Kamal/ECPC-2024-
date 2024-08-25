#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using sparse_t = vector<vector<ll>>;

constexpr int N{300'001}, LOG{19};

vector<int> adj[N];
ll val[N];
int depth[N], p[N];

void dfs_init(int curr, int prev, int dep = 0) {
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    p[node] = curr;
    dfs_init(node, curr, dep + 1);
  }

  depth[curr] = dep;
}


int calc(int u, int v, int w) {
  int res{};

  if(depth[u] > depth[v])
    swap(u, v);

  while(depth[v] > depth[u]) {
    res += (val[v] > w);
    v = p[v];
  }

  while(v != u) {
    res += (val[u] > w) + (val[v] > w);
    v = p[v];
    u = p[u];
  }

  return res + (val[u] > w);
}

void solve() {
  int n{}, q{};
  cin >> n >> q;

  for(int i{}; i < n; ++i) {
    cin >> val[i];
    p[i] = -1;
    adj[i].clear();
  }

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  dfs_init(0, -1);

  while(q--) {
    ll u{}, v{}, w{};
    cin >> u >> v >> w;

    --u; --v;
    
    cout << calc(u, v, w) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}




