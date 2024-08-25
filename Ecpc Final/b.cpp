#include <bits/stdc++.h>
using namespace std ;
int main() {
  int t ;
  cin >> t ;
  while (t--) {
    int n ;
    cin >> n ;
    long long x , y  , Sum = 0 ;
    while (n--){
      cin >> x >> y ;
      if (Sum <= y){
      Sum += x ;
      }
    }
    cout << Sum <<endl;
  }
}

