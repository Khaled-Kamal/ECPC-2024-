#include <bits/stdc++.h>
#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;

void Tamora() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

}

const ll mod = 1e9 + 7, inf = 1e9 + 5, N = 1e5 + 5, M = 1e4 + 7, LG = 18, P1 = 37, P2 = 31;

template<typename T>
class FenwickTree {
public:
    vector<T> tree;
    int n;

    void init(int n) {
        tree.assign(n + 2, 0);
        this->n = n;
    }

    T merge(T &x, T &y) { return x ^ y; }

    void update(int x, T val) {
        for (; x <= n; x += x & -x) {
            tree[x] = merge(tree[x], val);
        }
    }

    T getPrefix(int x) {
        if (x <= 0)return 0;
        T ret = 0;
        for (; x; x -= x & -x) {
            ret = merge(ret, tree[x]);
        }
        return ret;
    }

    T getRange(int l, int r) {
        return getPrefix(r) ^ getPrefix(l - 1);
    }


};

FenwickTree<int> bit;
vector<int> adj[N];
int sz[N], big[N], dep[N], anc[N][LG], in[N], out[N], ans[N], timer, Tamora7naka[N];
vector<pair<int, int>> paths[N], qu[N];

void dfsSize(int u, int par, int d) {
    sz[u] = 1 + paths[u].size(), anc[u][0] = par, dep[u] = d;
    in[u] = timer++;
    for (int k = 1; k < LG; k++)
        anc[u][k] = anc[anc[u][k - 1]][k - 1];
    for (auto v: adj[u]) {
        if (v == par)continue;
        dfsSize(v, u, d + 1);
        sz[u] += sz[v];
        if (big[u] == 0 || sz[v] > sz[big[u]])
            big[u] = v;
    }
    out[u] = timer++;
}

int binLift(int x, int jump) {
    for (int b = LG - 1; b >= 0; b--)
        if (jump & (1 << b))
            x = anc[x][b];

    return x;
}

int LCA(int a, int b) {
    if (dep[a] > dep[b])
        swap(a, b);
    int diff = dep[b] - dep[a];
    b = binLift(b, diff);
    if (a == b)
        return a;
    for (int bit = LG - 1; bit >= 0; bit--)
        if (anc[a][bit] != anc[b][bit])
            a = anc[a][bit], b = anc[b][bit];

    return anc[a][0];
}

bool isAncestor(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}


void collect(int u, int par) {
    for (auto [v, p]: paths[u])
        bit.update(in[v], p);

    for (auto v: adj[u]) {
        if (v == par)continue;
        collect(v, u);
    }
}


void dfs(int u, int par, bool keep) {
    for (auto v: adj[u]) {
        if (v == par || v == big[u])continue;
        dfs(v, u, false);
    }
    if (big[u])
        dfs(big[u], u, true);

    for (auto [v, p]: paths[u])
        bit.update(in[v], p);
    for (auto v: adj[u]) {
        if (v == par || v == big[u])continue;
        collect(v, u);
    }

    for (auto [v, idx]: qu[u])
        if (isAncestor(v, u)) {
            if (u != v) {
                int ancChild = binLift(u, dep[u] - dep[v] - 1);
                ans[idx] = bit.getRange(1, in[ancChild] - 1) ^ bit.getRange(out[ancChild] + 1, timer);
            } else
                ans[idx] = bit.getRange(1, in[u]) ^ bit.getRange(out[u], timer) ^ Tamora7naka[u];
        } else
            ans[idx] = bit.getRange(in[v], out[v]);


    if (!keep)
        collect(u, par);

}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        paths[i].clear();
        qu[i].clear();
        big[i] = 0;
        Tamora7naka[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    timer = 1;
    bit.init(2 * n + 2);
    dfsSize(1, 0, 0);
    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        paths[u].emplace_back(v, p);
        if (u != v)
            paths[v].emplace_back(u, p);
        int lca = LCA(u, v);
        if (u != lca && v != lca)
            Tamora7naka[lca] ^= p;
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (dep[u] < dep[v])
            swap(u, v);
        qu[u].emplace_back(v, i);
    }
    dfs(1, 0, false);
    for (int i = 0; i < q; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    Tamora();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
    return 0;
}
