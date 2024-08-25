#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int ans[N];

vector<int> flt;
vector<int> G[N];


int a[N], f[N], sz[N], in[N], out[N];

unordered_map<int, int> mp[N];

int add(int node, int val, int f = 1) {
    if (mp[node].find(val) != mp[node].end()) {
        mp[node][val] += f;
        return 0;
    }

    if (mp[node].count(val - 1) && mp[node].count(val + 1)) {
        mp[node][val] += f;
        return -1;
    }

    if (mp[node].count(val - 1) || mp[node].count(val + 1)) {
        mp[node][val] += f;
        return 0;
    }
    mp[node][val] += f;
    return 1;
}

int rmv(int node, int val, int f = 1) {
    if (mp[node][val] == 1) {
        mp[node][val]--;
        mp[node].erase(val);
        if (mp[node].count(val - 1) && mp[node].count(val + 1))
            return 1;
        else if (mp[node].count(val - 1) || mp[node].count(val + 1))
            return 0;
        else
            return -1;

    }
    mp[node][val]--;
    return 0;
}


void dfs(int node, int par, bool keep, int &val) {
    ans[node] += val;

    int mx = -1, fat = -1;
    for (auto &ch: G[node]) {
        if (ch == par)
            continue;
        if (sz[ch] > mx)
            mx = sz[ch], fat = ch;
    }

    for (int i = in[node]; i < out[node]; i++) {
        if (flt[i] == fat) {
            i = out[flt[i]] - 1;
            continue;
        }
        val += add(1, a[flt[i]]);
    }


    if (~fat)
        dfs(fat, node, 1, val);

    for (auto &ch: G[node]) {
        if (ch == par || ch == fat)
            continue;

        for (int i = in[ch]; i < out[ch]; i++)
            val += rmv(1, a[flt[i]]);

        dfs(ch, node, 0, val);
    }
}

int dfs2(int node, int par = -1) {
    int ret = 0;
    int val = 0;
    sz[node] = 1;

    in[node] = flt.size();
    flt.push_back(node);
    for (auto &ch: G[node]) {
        if (ch == par)
            continue;

        int swval = dfs2(ch, node);
        ret += swval;
        sz[node] += sz[ch];

        if (mp[ch].size() > mp[node].size())
            mp[node].swap(mp[ch]), swap(val, swval);

        for (auto &it: mp[ch])
            val += add(node, it.first, it.second);
    }
    out[node] = flt.size();

    ans[node] = ret;
    val += add(node, a[node]);

    return val;
}

void solve() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 0, u, v; i < n - 1; i++)
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);

    dfs2(1);
    for (int i = 1; i <= n; i++)
        mp[i].clear();
//    for (int i = 1; i <= n; i++)
//        cout << i << ' ' << ans[i] << '\n';
    int temp = 0;
    dfs(1, 1, 0, temp);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}

int32_t main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}       