#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);


    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }


    int top = -1, bottom = -1, left = -1, right = -1;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '+') {
                if (top == -1) {
                    top = i;
                    left = j;
                }
                bottom = i;
                right = j;
            }
        }
    }


    int area = 0;
    for (int i = top + 1; i < bottom; ++i) {
        for (int j = left + 1; j < right; ++j) {
            if (grid[i][j] == '.') {
                ++area;
            }
        }
    }

  
    cout << area << endl;
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