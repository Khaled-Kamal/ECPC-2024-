#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    string n, d;
    cin >> n >> d;
    int nl = n.length();
    int l = 0, r = nl - 1;
    char ans[nl];
    for (int i = 0; i < nl; i += 2) {
        ans[l++] = n[i];
        if (i + 1 < nl) {
            ans[r--] = n[i + 1];
        }
    }
    for (int i = 0; i < d.length(); ++i) {
        if (d[i] == '/') continue;
        int c = d[i] - 'A';
        d[i] = c + '0';
    }
    for (char c: ans) {
        cout << c;
    }
    cout << '\n' << d;
        
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int tc = 1 ;
   // cin >> tc ;
    for(int i = 1 ; i <= tc ; i++)
    {
       solve();
    }
   
}