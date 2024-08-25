#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5, M = 1e6 + 6, mod = 998244353;
void solve(){
      int n, m;
        cin >> n >> m;
        int best = 1e9;
        int best2 = 1e9;
        int ans = (n + m - 2) * 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char x;
                cin >> x;
                if (x == 'o') {
                    best = min(best, (i + j) * 2);
                    best2 = min(best2, ((n - i - 1) + (m - j - 1)) * 2);
                }
            }
        }
        ans = min(ans,best + best2 + 1);
        cout << ans << '\n';
        
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int tc = 1 ;
    cin >> tc ;
    for(int i = 1 ; i <= tc ; i++)
    {
       solve();
    }
   
}