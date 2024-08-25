#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 1;
ll dp[3][3][N], a[N], ans[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp[0][0][i] = max(dp[0][0][i - 1], a[i]);

        dp[0][1][i] = a[i] + max(dp[0][1][i - 1], dp[0][0][i - 1]);
        dp[1][1][i] = max(a[i] + dp[1][1][i - 1], dp[0][1][i - 1]);

        dp[0][2][i] = max({dp[0][2][i - 1], dp[0][1][i - 1], dp[1][1][i - 1]});
        ans[i] = max({dp[0][2][i], dp[1][1][i], dp[0][1][i]});
    }

    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
        dp[0][0][i] = dp[0][0][i - 1];

        dp[0][1][i] = a[i] + max(dp[0][1][i - 1], dp[0][0][i - 1]);
        dp[1][1][i] = max(a[i] + dp[1][1][i - 1], dp[0][1][i - 1]);

        dp[0][2][i] = max(dp[0][2][i - 1], dp[0][1][i - 1]);
        dp[1][2][i] = max(dp[1][2][i - 1], dp[1][1][i - 1]);
        dp[2][2][i] = max(dp[2][2][i - 1], a[i] + dp[1][2][i]);

        cout << max({ans[i], dp[2][2][i], dp[0][2][i]}) << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}