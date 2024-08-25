#include <bits/stdc++.h>
using namespace std;
#define int long long
void KKB()
{
     int a , b , c ;
     cin >> a >> b >> c ;

     int sum = a + b + c ;
     if(sum % 2 == 0)
     {
         cout << "Alice" << '\n';
     }
     else
     {
         cout << "Bob" << '\n';
     }
}
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

     KKB();
}