#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(a) a.begin() , a.end()
#define alr(a) a.rbegin() , a.rend()
const int mod = 1e9 + 7;
int add(int a, int b) {
    a %= mod, b %= mod;
    return (a + b) % mod;
}
int mul(int a, int b) {
    a %= mod, b %= mod;
    return (a * b) % mod;
}
int power(int a, int b) {
    if(!b) return 1;
    int ans = power(a, b >> 1);
    ans = mul(ans, ans);
    if(b & 1) ans = mul(ans, a);
    return ans;
}
int nCr(int n, int r) {
    int one = 1, two = 1;
    for(int i = 1 ; i <= r ; i++) {
        one = mul(one, add(n, i));
        two = mul(two, i);
    }
    return mul(one, power(two, mod - 2));
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector < int > primes;
    for(int i = 2 ; i * i <= n ; i++) {
        while(n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }
    if(n > 1) 
        primes.push_back(n);
    sort(all(primes));
    int ans = 1;
    for(int i = 0 ; i < (int)primes.size() ; i++) {
        int j = i;
        while(j < (int)primes.size() && primes[j] == primes[i]) {
            j += 1;
        }
        int cnt = j - i;
        i = j - 1;
        ans = mul(ans, nCr(k, cnt));
    }
    cout << ans << endl;
    return 0;
}