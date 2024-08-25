#include <bits/stdc++.h>
using namespace std;
#define int long long
void KKB() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int y  = 0;
    int z  = 0;

    bool f = true;
    for(int i = 0; i < n; ++i) {
        if (f) {
            y += v[n - 1 - i / 2];
        } else {
            z += v[i / 2];
        }
       f = !f;
    }

    cout << y << " " << z << '\n';
}
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

         KKB();
     

}