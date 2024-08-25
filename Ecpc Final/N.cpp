#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tt, tc;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    ll ans = 0;
    vector<pair<ll, int>> st;
    for (int i = n - 1; i >= 0; --i) {
        ll sum = a[i];
        while (!st.empty() && sum >= a[st.back().second]) {
            sum += st.back().first;
            ans += st.back().second - i;
            st.pop_back();
        }
        st.emplace_back(sum, i);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    tt = 1, tc = 1; // cin >> tt;
    while (tt--) solve(), tc++;
}
