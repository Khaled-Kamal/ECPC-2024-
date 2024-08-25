#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long
#define endl '\n'
#define all(a) a.begin() , a.end()
#define alr(a) a.rbegin() , a.rend()
const int N = 1e5 + 5, mod = 1e9 + 7;
int Add(int a, int b) {
    a -= (a >= mod? mod : 0);
    b -= (b >= mod? mod : 0);
    a += b;
    a -= (a >= mod? mod : 0);
    return a;
}
int Sub(int a, int b) {
    a -= (a >= mod? mod : 0);
    b -= (b >= mod? mod : 0);
    a -= b;
    a += mod;
    a -= (a >= mod? mod : 0);
    return a;
}
int Mul(int a, int b) {
    return ((a % mod) * (b % mod)) % mod;
}
vector < int > inv(N);
vector < vector < int >> divs(N);
void build() {
    inv[0] = inv[1] = 1;
    for(int i = 2 ; i < N ; i++) {
        inv[i] = Mul(inv[mod % i], (mod - mod / i));
    }
    for(int i = 1 ; i < N ; i++) {
        for(int j = i ; j < N ; j += i)
            divs[j].push_back(i);
    }
}

int n;
vector < int > a, answer(N);
vector < vector < int >> vals(N);
int solve(vector < int > arr) {
    set < int > s;
    for(auto i : arr) {
        for(auto j : divs[a[i]]) {
            s.insert(j);
            vals[j].push_back(i);
        }
    }
    vector < int > gcds;
    for(auto i : s) gcds.push_back(i);
    reverse(all(gcds));
    int ans = 0;
    for(auto i : gcds) {
        int sum = 0;
        for(auto j : vals[i]) {
            sum = Add(sum, a[j] * j);
        }
        answer[i] = Add(answer[i], Mul(sum, sum));
        for(auto j : divs[i]) {
            if(j != i)
                answer[j] = Sub(answer[j], answer[i]);
        }
        ans = Add(ans, Mul(answer[i], inv[i]));
    }
    for(auto i : gcds) {
        vals[i].clear();
        answer[i] = 0;
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    build();

    cin >> n;
    a = vector < int > (n + 5);
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    vector < int > ans(n + 1);
    int sum = 0;
    for(int g = n ; g >= 1 ; g--) {
        vector < int > arr;
        for(int j = g ; j <= n ; j += g) {
            ans[g] = Sub(ans[g], ans[j]);
            arr.push_back(j);
        }
        ans[g] = Add(ans[g], solve(arr));
        sum = Add(sum, Mul(ans[g], inv[g]));
    }
    cout << sum << endl;
    return 0;
}