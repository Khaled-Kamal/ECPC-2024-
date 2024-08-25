#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
   int a , b  ;
   cin >> a >> b ;
   if(a < b && a + b == 100) {
       cout << "Sharm El-shaikh";
   }
   else if(a > b && a + b == 100)
   {
       cout << "Luxor" ;
   }
   else
   {
       cout << "impossible";
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