#include <bits/stdc++.h>
using namespace std;
#define int long long
void KKB(int n) {

    int x = 2 * n;
    int y = 3 * n;
    int z = 6 * n;

    cout << x << " " << y << " " << z << '\n';
}
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     int t = 1 ;
     cin >> t ;
     while(t--)
     {
         int n ;
         cin >> n ;
         KKB(n);
     }

}