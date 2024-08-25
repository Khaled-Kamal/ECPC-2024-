#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5000 + 5, mod = 1e9 + 7;
vector<vector<int>> dp;
int a[N];
vector<int> subtree[N];
vector<int> adj[N];
int ans = 0, k;

void dfs(int u = 1, int p = -1) {
    auto &myDp = dp[u];
    auto &myTree = subtree[u];

    subtree[u].push_back(a[u]), myDp[a[u]]++, myDp[0]++;

    for (auto &v: adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        auto &childDP = dp[v], childTree = subtree[v];

        if (childTree.size() > myTree.size())
            swap(childTree, myTree), swap(myDp, childDP);

        for (auto &value: childTree) {
            for (int i = k - value; i >= 0; --i) {
                myDp[value + i] = (myDp[value + i] + myDp[i]);
                if (myDp[value + i] > mod)
                    myDp[value + i] -= mod;
            }
            myTree.push_back(value);
        }

    }
    ans = ans + myDp[k];
    if (ans > mod)
        ans -= mod;
}

void solve(int _t) {
    int n;
    cin >> n >> k;
    dp.assign(n + 5, vector<int>(k + 1));
    for (int i = 1; i <= n; ++i)cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    cout << ans;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
//    cin >> _t;

    for (int i = 1; i <= _t; ++i)
        solve(i);
    return 0;
}