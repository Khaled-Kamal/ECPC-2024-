#include <bits/stdc++.h>
using namespace std;
int main() {
    int n ;
    cin>>n ;
    map<pair<int,int>,int> cnt;
    for(int i = 0;i<n;i++) {
        int x1,y1, x2, y2;
        cin>>x1>>y1 >> x2 >> y2;
        for(int k = x1; k <= x2; k++)
            for(int j = y1; j <= y2; j++) {
                cnt[{k, j}]++;
            }
    }
    int ans = 0;
    for(auto [p, j] : cnt) ans = max(ans, j);
    cout << ans;

    return 0;
}
