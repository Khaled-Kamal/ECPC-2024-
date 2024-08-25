#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    
        int n;
        cin >> n;
        vector < int > a(n);
        for(auto &i : a) cin >> i;
        map < int , int > mp;
        for(int i = 0 ; i < n ; i++) {
            mp[a[i]] = i;
        }
        int q, shift{};
        cin >> q;
        while(q--) {
            int ty;
            cin >> ty;
            if(ty == 1) {
                int x;
                cin >> x;
                shift += x;
            } else {
                int x;
                cin >> x;
                if(mp.find(x) != mp.end()) {
                    cout << ((((mp[x] + shift) % n) + n) % n) + 1 << '\n';
                } else {
                    cout << -1 << '\n';
                }
            }
        }
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