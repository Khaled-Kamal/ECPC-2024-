#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a , b ;
    cin >> a >> b ;

    if(a == 0 && b > 0)
    {
        cout << "Silver";
    }
    else if(a > 0 && b == 0)
    {
        cout << "Gold" ;
    }
    else
    {
        cout << "Alloy";
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