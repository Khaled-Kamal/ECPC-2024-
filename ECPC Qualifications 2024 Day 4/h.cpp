#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> x(n);
    int mx = 0 ;
    for(int i =0;i<n;i+=2) x[i] = a[i/2];
    for(int i =1;i<n;i+=2) x[i] = a[i/2 + (n+1)/2];
    for(int i = 1; i < n - 1; i++) {
        if(x[i] > x[i-1] and x[i] > x[i+1]) mx++;
    }
    if(mx >= k) for(int z : x) cout << z << ' ';
    else cout << -1;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
