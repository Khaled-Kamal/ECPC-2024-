
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    long long r, n;
        cin >> r >> n;

        double ex = 5 / 0.85786438;
        double ans = r / (pow(ex, n));
        cout << setprecision(8) << ans << '\n';
}
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

     int t = 1 ;
    cin >> t ;
     while(t--)
     {
         solve();
     }
    return 0 ;
}