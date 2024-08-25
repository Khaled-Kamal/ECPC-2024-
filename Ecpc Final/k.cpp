#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n ;
    cin >> n ;
    vector<int> v(n);
    int sum= 0;
    for (int i = 0; i <n ; ++i) {
        cin >> v[i];
        sum+=v[i];
    }
    cout << sum ;
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
         cout << '\n';
     }
    return 0 ;
}