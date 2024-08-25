
#include <bits/stdc++.h>
#define ll long long
#define u64 __int128
#define u128 __int128
using namespace std;
const int N = 5e5 + 5;
const ll MOD = 1e9 + 7, MAX = 1e18;
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, m = 0, k;
const int maxN = 1e6 + 50;
bool primes[maxN];
vector<int> pr;
void seive()
{
    memset(primes, 1, sizeof(primes));
    primes[0] = primes[1] = 0;
    for (ll i = 2; i < maxN; i++)
    {
        if (primes[i])
        {
            pr.push_back(i);
            for (ll j = i * i; j < maxN; j += i)
                primes[j] = 0;
        }
    }
}
void fn()
{
    cin >> n >> m;
    ll g = __gcd(n, m);
    n /= g;
    m /= g;
    ll ans = 0;
    // cout << pr.size() * 100 * 60 << '\n';
    for (auto x : pr)
    {
        if (x > n)
            break;
        int cnt = 0;
        while (n % x == 0)
        {
            cnt++;
            n /= x;
        }
        if (cnt % 2 == 1)
        {
            cout << "-1\n";
            return;
        }
        ans += cnt / 2;
    }
    for (auto x : pr)
    {
        if (x > m)
            break;
        int cnt = 0;
        while (m % x == 0)
        {
            cnt++;
            m /= x;
        }
        if (cnt % 2 == 1)
        {
            cout << "-1\n";
            return;
        }
        ans += cnt / 2;
    }
    if (n != 1)
    {
        ll z = sqrt(n);
        if (z * z == n)
            ans++;
        else
        {
            cout << "-1\n";
            return;
        }
    }
    if (m != 1)
    {
        ll z = sqrt(m);
        if (z * z == m)
            ans++;
        else
        {
            cout << "-1\n";
            return;
        }
    }
    cout << ans << '\n';
}

int main()
{
    seive();
    fastio();
    int t = 1;
    cin >> t;
    while (t--)
        fn();
    return 0;
}
/*
1/n - 1/(n+1) - 1/(n+2);

*/