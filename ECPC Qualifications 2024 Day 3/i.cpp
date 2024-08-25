#include <bits/stdc++.h>
#define GO cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
typedef long long ll;
using namespace std;

int main()
{
    GO
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll dp[n + 2] = {0};
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            a[i] = x + i;
        }
        stack<pair<int, int>> s;
        s.push({0, n + 1});
        ll ans = 0;
        for(int i = n; i >= 0; i--){
            while(s.size() && a[i] < s.top().first) s.pop();
            ll nxt = s.top().second;
            s.push({a[i], i});
            ll v = a[i] - i;
            ll cur = dp[nxt];
            if(nxt == n + 1){
                ll cnt = min(nxt - i, v);
                cur = cnt * (2 * v - cnt + 1) / 2;
            }
            else{
                ll cnt = nxt - i;
                cur += cnt * (2 * v - cnt + 1) / 2;
            }
            dp[i] = cur;
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
