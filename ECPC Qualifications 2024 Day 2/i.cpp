#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(s) (int)(s).size()
#define all(s) s.begin(),s.end()

void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int mod = 1e9 + 7;


ll power(ll a , ll n){
    if(n == 0)
        return 1;

    ll res = power(a , n / 2);
    res = res * res % mod;
    if(n & 1)
        res = res * a % mod;
    return res;
}

const int N = 2e6 + 9;

ll fact[N] , inv_fact[N];

ll ncr(ll n , ll r){
    if(r > n)
        return 0;
    ll num = fact[n] , denum = inv_fact[r] * inv_fact[n - r] % mod;
    return num * denum % mod;
}

void solve() {
    ll n , a, b;
    cin >> n >> a >> b;
    ll m = a - n - 1;

    b -= n;
    ll tot = power(ncr(n + b , n) , mod - 2);
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ll num = ncr(n , i) * ncr(n + b - (m + 1) * i , n) % mod;
        //out << ncr(n,i) << " " << n - 1 + b - (m + 1) * i  << " ~\n";
        if(i % 2 == 0)
            ans = (ans + num) % mod;
        else ans = (ans - num + mod) % mod;
    }

    cout << ans * tot % mod  << "\n";
}

int main() {
    Speed();
    int tc = 1;
    cin >> tc;
    fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;

    for(ll i = 2; i < N; i++){
        fact[i] = fact[i - 1] * i % mod ; 
        inv_fact[i] = power(fact[i] , mod - 2);
        
    }

    while (tc--) {
        solve();
    }
    return 0;
}