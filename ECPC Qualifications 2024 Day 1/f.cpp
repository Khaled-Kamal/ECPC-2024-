
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 9;
int spf[N];
 

 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int nu;
        cin >> nu;
        for (int i = 2; i * i <= nu; i++) {
            while (nu % i == 0) {
                nu /= i;
                v.push_back(i);
            }
        }
        if (nu != 1) {
            v.push_back(nu);
        }
    }

    if (v.size() % k == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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