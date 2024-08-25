#include <bits/stdc++.h>

using namespace std;
#define int long long

struct node {
  int ch[2]{}, frq[2]{}, sz{};

  int &operator[](int x) {
    return ch[x];
  }
};

const int M = 60;

struct BT {
  vector<node> nodes;

  int newNode() { return nodes.emplace_back(), nodes.size() - 1; }

  void init() { nodes.clear(), newNode(); }

  BT() { init(); }

  void update(int val, int op) { /// 1 -> add , -1 -> delete
    int u = 0;
    for (int i = M - 1; i >= 0; --i) {
      int v = val >> i & 1;
      if (!nodes[u][v]) {
        nodes[u][v] = newNode();
      }
      nodes[u].frq[v] += op;
      nodes[u].sz += op;
      u = nodes[u][v];
    }
    nodes[u].sz++;
  }

  int query(int x) {
    int ans = 0, u = 0;
    for (int i = M - 1; i >= 0 && u >= 0; --i) {
      int v = x >> i & 1;
      if (nodes[u].frq[v]) {
        u = nodes[u][v];
      } else {
        u = nodes[u][!v];
        ans |= 1LL << i;
      }
    }
    return ans;
  }

};

BT bt;
const int N = 5e5 + 5;
vector<int> adj[N];
int arr[N], answers[N];

void dfs(int u) {
  answers[u] = bt.query(arr[u]);
  bt.update(arr[u], +1);
  for (int v: adj[u]) {
    dfs(v);
    answers[u] = min(answers[v], answers[u]);
  }
  bt.update(arr[u], -1);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 2, p; i <= n; ++i) {
    cin >> p, adj[p].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  bt.update(arr[1], +1);
  for (int v: adj[1]) {
    dfs(v);
  }
  int u, q;
  cin >> q;
  while (q--) {
    cin >> u;
    cout << answers[u] << '\n';
  }
  return 0;
}