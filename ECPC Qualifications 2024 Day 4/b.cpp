#include <bits/stdc++.h>
#define int long long
#define add emplace_back
#define all(a) a.begin(), a.end()
#define sz(s) (int)(s.size())
using namespace std;

signed main(){
     ios_base::sync_with_stdio(false);
     cin.tie(0);

     int n, q; cin >> n >> q;
     vector<int> a(n), prefix(n + 1);
     for(auto &x : a) cin >> x;
     sort(a.begin(), a.end());
     for(int i = 0; i < n; i++)
          prefix[i + 1] = prefix[i] + a[i];
     while(q--){
          int x; cin >> x;
          int idx = lower_bound(all(a), x) - a.begin();
          cout << (x * idx - prefix[idx]) * 50 << '\n';
     }
}