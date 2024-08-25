#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(int _t) {
    int n,m,e;cin>>n>>m>>e;
    int cnt[24]={};
    for (int i = 0; i < n; ++i) {
        int a;cin>>a;
        bool bad[24]={};
        for (int j = 0; j < e; ++j) {
            bad[a]=1;
            a=(a+1)%24;
        }
        for (int j = 0; j < 24; ++j) {
            bool ok=1;
            for (int k = 0; k < m; ++k) {
                ok&=!bad[(j+k)%24];
            }
            cnt[j]+=ok;
        }
    }
    int ans=0;
    for (int i = 0; i < 24; ++i)
        ans=max(ans,cnt[i]);
    cout<<ans;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;

    cin >> _t;

    for (int i = 1; i <= _t; ++i)
        solve(i), cout << '\n';
    return 0;
}