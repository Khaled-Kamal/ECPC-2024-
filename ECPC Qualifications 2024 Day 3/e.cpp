#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
#define el '\n'
#define popcount __builtin_popcountll
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vi vector<int>
#define sz(x) (int)x.size()
#define rep(i,l,r) for(int i = l;i < r;i++)
const int mod = 1e9 + 7, INF = 1e9 + 10;
const ld PI = acos(-1), eps = 1e-7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

template<class T>
using ordered_set = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;

int mul(int a,int b){
    return (ll) a * b % mod;
}

int modPow(int b,int k){
    int res = 1;
    while(k){
        if(k & 1) res = mul(res,b);
        b = mul(b, b);
        k >>= 1;
    }
    return res;
}

int inv(int x){
    return modPow(x,mod - 2);
}

int nCk(int n,int k){
    int ret = 1;
    for(int i = 1;i <= k;i++) {
        ret = mul(ret, n - i + 1);
        ret = mul(ret, inv(i));
    }
    return ret;
}

int solve(int n, int up, int p){
    int ans = nCk(n + p - 1, p - 1);
    for(int i = 1;i <= p;i++){
        int rem = n - i * (up + 1);
        if(rem < 0)
            break;
        int cnt = mul(nCk(p, i), nCk(rem + p - 1, p - 1));
        if(i % 2){
            ans = (ans - cnt + mod) % mod;
        }else{
            ans = (ans + cnt) % mod;
        }
    }
    return ans;
}

int main() {
    ios;
    int t;
    cin >> t;
    while(t--) {
        int p;
        cin >> p;
        int up = (p + 1) / 2 - 1;
        int all = solve(p - 4, up - 1, 4);
        int ans = 0;
        if(p % 4 == 0) {
            ans++;
            all = (all - 1 + mod) % mod;
        }
        if(p % 2 == 0) {
            int pp = p / 2;
            int x = pp - up, y = up;
            int cnt = 1 + (y - x) / 2;
            if(p % 4 == 0) cnt--;
            ans += cnt;
            all = (all - 2 * cnt % mod + mod) % mod;
        }
        // cout << all << " " << up << el;
        ans = (ans + mul(all, inv(4))) % mod;
        cout << ans << el;
    }
}