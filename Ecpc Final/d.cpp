#include<iostream>
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 3e5 + 6, mod = 1e9 + 7;
using ii = pair<int, int>;

vector<ii> ranges;
set<ii> cache;
int go[N];
int n, q;
const int BLK = 450;
void build() {
    for(auto x : cache) go[x.first] = max(go[x.first], x.second);
    for(int i = 1; i <= n; i++) go[i] = max(go[i-1], go[i]);
    cache.clear();
}
void doWork() {
    cin >> n >> q;
    for(int i = 0; i < q; i++) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if(tp==1) cache.insert({l, r});
        else {
            int cur = l, ans = 0;
            auto it = cache.begin();
            while (cur <= r) {
                int mx = go[cur];
                while (it != cache.end() && it->first <= cur) mx = max(mx, it->second), it++;
                if(mx < cur) {
                    ans = -1;
                    break;
                }
                ans += 1;
                cur = mx + 1;
            }
            cout << ans << '\n';
        }

        if(cache.size() == BLK) build();
    }
}

int main() {
    IO
    int t = 1;

//    cin >> t;

//    return 0;
    for (int i = 1; i <= t; i++) {
        //  cout << "Case #" << i << ": ";
        doWork();
    }
}
// 6 4 3 1 2