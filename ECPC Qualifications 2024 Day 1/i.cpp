#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
int l, dep[N], dp[N][2];
vector<int> al[N];
string s;

void preCalc(int u, int d, int p = 0) {
    dep[u] = 1;
    for (int v : al[u]) {
        if (v != p) {
            preCalc(v, d + 1, u);
            dep[u] = max(dep[u], dep[v] + 1);
        }
    }
}

void dfs(int u, int d, bool mx, int p = 0) {
    int &ret = dp[u][mx];
    if (~ret) return;
    ret = 0;

    int r = 9;
    if (mx) r = s[d] - '0';

    for (int digit = 0; digit <= r; digit++) {
        long long res = 1;
        for (int v : al[u]) {
            bool state = (mx && (digit == r));
            if (v != p) {
                dfs(v, d + 1, state, u);
                res = (1ll * res * dp[v][state]) % mod;
            }
        }
        ret += res;
        if (ret >= mod) ret -= mod;
    }
}

void solve() {

    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    cin >> l >> s;
    preCalc(1, 0);
    reverse(s.begin(), s.end());
    while (s.size() < dep[1]) s.push_back('0');
    reverse(s.begin(), s.end());
    dfs(1, 0, (l <= dep[1]));
    cout << dp[1][(l <= dep[1])];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }

    return 0;
}
