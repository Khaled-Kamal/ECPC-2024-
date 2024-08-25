#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
ll modpow(ll b, ll e)
{
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1)
            ans = ans * b % mod;
    return ans;
}

// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
void ntt(vl &a)
{
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vl rt(2, 1);
    for (static int k = 2, s = 2; k < n; k *= 2, s++)
    {
        rt.resize(n);
        ll z[] = {1, modpow(root, mod >> s)};
        rep(i, k, 2 * k) rt[i] = rt[i / 2] * z[i & 1] % mod;
    }
    vi rev(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            rep(j, 0, k)
            {
                ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
                a[i + j + k] = ai - z + (z > ai ? mod : 0);
                ai += (ai + z >= mod ? z - mod : z);
            }
}
vl conv(const vl &a, const vl &b)
{
    if (a.empty() || b.empty())
        return {};
    int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s),
        n = 1 << B;
    int inv = modpow(n, mod - 2);
    vl L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    rep(i, 0, n)
        out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    return {out.begin(), out.begin() + s};
}

int n, k, a;
vl modpow(vl b, ll e)
{
    vl ans(b.size(), 0);
    ans[0] = 1;
    for (; e; b = conv(b, b), e /= 2)
    {
        b.resize(n + 1);
        if (e & 1)
        {
            ans.resize(b.size(), 0);
            ans = conv(ans, b);
        }
    }
    return ans;
}

ll euclid(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k >> a;

    vl poly(k + 1, 1);
    for (int i = 1; i <= k; i++)
    {
        poly[i] = (poly[i - 1] * i) % mod;
    }

    for (int i = 0; i <= k; i++)
    {
        ll x, y;
        euclid(poly[i], mod, x, y);
        x = (x % mod + mod) % mod;
        poly[i] = x;
    }

    poly = modpow(poly, a);

    ll fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = (fact * i) % mod;
        ll ans = (poly[i] * fact) % mod;
        cout << ans << " ";
    }

    return 0;
}