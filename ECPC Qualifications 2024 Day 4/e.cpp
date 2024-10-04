#include <bits/stdc++.h>

using namespace std;
#define ll long long
int tt, tc;

const int mod = 1e9 + 7;
int add(int x, int y) { return (x + y) % mod; }
int sub(int x, int y) { return (x - y + mod) % mod; }
int mul(int x, int y) { return (x * 1LL * y) % mod; }
int modpow(int n, ll k) {
    int res = 1;
    while (k) {
        if (k & 1) res = mul(res, n);
        n = mul(n, n);
        k >>= 1;
    }
    return res;
}
int divide(int a, int b) { return mul(a, modpow(b, mod - 2)); }

void solve() {
    ll n;
    cin >> n;
    n += 1;
    cout << sub(divide(add(modpow(3, n), sub(2, mul(3, (n & 1 ? sub(0, 1) : 1)))), 8), 1) << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    tt = 1, tc = 1; // cin >> tt;
    while (tt--) solve(), tc++;
}
