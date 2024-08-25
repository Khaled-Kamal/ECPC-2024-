#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c) {
      cout << "-1\n";
    } else {
      cout << a / 2.0 << ' ' << b / 2.0 << '\n';
    }
  }
  return 0;
}