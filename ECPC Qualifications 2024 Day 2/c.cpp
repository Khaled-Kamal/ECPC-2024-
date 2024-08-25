#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(a) a.begin() , a.end()
#define alr(a) a.rbegin() , a.rend()

int n;
vector < int > dep, sum;
vector < vector < int >> adj, parent;

void dfs(int node, int par) {
    sum[node] = 1;
    parent[0][node] = par;
    dep[node] = dep[par] + 1;
    for(auto ch : adj[node]) {
        if(ch == par) continue;
        dfs(ch, node);
        sum[node] += sum[ch];
    }
}

int LCA(int u, int v) {
    if(dep[u] < dep[v]) {
        swap(u, v);
    }
    int want = dep[u] - dep[v];
    for(int i = 19 ; i >= 0 ; i--) {
        if(want & (1ll << i)) {
            u = parent[i][u];
        }
    }
    if(u == v) return u;
    for(int i = 19 ; i >= 0 ; i--) {
        if(parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}
int go(int u, int dis) {
    for(int i = 19 ; i >= 0 ; i--) {
        if(dis & (1 << i)) {
            u = parent[i][u];
        }
    }
    return u;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    dep = sum = vector < int > (n + 1);
    adj = vector < vector < int >> (n);
    parent = vector < vector < int >> (20, vector < int > (n));

    for(int i = 1 ; i < n ; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 0);

    for(int i = 1 ; i < 20 ; i++) {
        for(int j = 0 ; j < n ; j++) 
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
    }

    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        int lc = LCA(u, v);
        // cout << lc << endl;
        int dis = dep[u] + dep[v] - 2 * dep[lc];
        // cout << dis << endl;
        int want = (dis - 1) >> 1;
        int alice = 0, bob = 1;
        if(dep[u] < dep[v]) {
            swap(alice, bob);
            swap(u, v);
        }
        u = go(u, want);
        int cnt1 = sum[u], cnt2 = n - sum[u];
        if(dis % 2 == 0) {
            if(parent[0][u] == lc) {
                v = go(v, want);
                cnt2 = sum[v];
            } else {
                cnt2 -= (sum[parent[0][u]] - sum[u]);
            }
        }
        if(alice == 1) swap(cnt1, cnt2);
        cout << (cnt1 > cnt2? "Alice" : (cnt1 == cnt2? "Draw" : "Bob")) << endl;
    }
    return 0;
}