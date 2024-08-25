
#include <bits/stdc++.h>
using namespace std;

void solve()
{
   int n, k;
    cin >> n >> k;
    int cnt = 1;
    vector<long long> ans(n);
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            ans[j] = cnt++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

     int t = 1 ;
  //   cin >> t ;
     while(t--)
     {
         solve();
     }
    return 0 ;
}