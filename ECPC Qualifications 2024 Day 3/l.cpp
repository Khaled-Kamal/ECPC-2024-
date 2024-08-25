#include <bits/stdc++.h>
using ll = long long;
using namespace std;
struct SL {
    map<ll, ll> dp;
    friend void merge(SL &s, SL &t) {
        map<ll, ll> me = s.dp;
        for (auto &[x, ti1]: t.dp) {
            for (auto &[y, ti2]: me) {
                ll d = x / gcd(x, y) * y;
                if (s.dp.count(d))
                    s.dp[d] = min(s.dp[d], ti1 + ti2);
                else
                    s.dp[d] = ti1 + ti2;
            }
        }
    }
};
vector<ll> val;
vector<vector<ll>> adj;
vector<SL> sl;
ll n, lc, ans;
void dfs(int u, int p) {
    sl[u].dp[val[u]] = 1;
    for (auto &v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        merge(sl[u], sl[v]);
    }
    if (sl[u].dp.count(lc))
        ans = min(ans, sl[u].dp[lc]);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    adj.assign(n, {});
    val.assign(n, {});
    sl.assign(n, {});
    ans = n, lc = 1;
    for (auto &x: val) {
        cin >> x;
        lc = x / __gcd(lc, x) * lc;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}