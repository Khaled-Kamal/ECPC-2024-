#include <bits/stdc++.h>
using namespace std;
#define int long long
void KKB()
{
     int a , b ;
     cin >> a >> b ;

     if(a >b)
     {
         cout << "Mary" ;
     }
     else if(a < b)
     {
         cout << "John";
     }
     else
     {
         cout << "Tie";
     }
}
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

     KKB();
}