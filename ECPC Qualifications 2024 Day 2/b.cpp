#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2 , MOD = 998244353;

typedef long long ll ;

ll p[2] = {31, 29};
ll m[2] = {(int)1e9 + 9, (int)1e9 + 7};
ll po[2][N];


int processed[N] , vid ;
vector<int> ad[N] ;
int subtree[N];

int a[N];

int get_subtree_sizes(int node, int parent = 0) {
    subtree[node] = 1;
    for (int i : ad[node]) if (processed[i] != vid && i != parent)
            subtree[node] += get_subtree_sizes(i, node);
    return subtree[node];
}

int get_centroid(int desired, int node, int parent = 0) {
    for (int i : ad[node])
        if (processed[i] != vid && i != parent && subtree[i] >= desired)
            return get_centroid(desired, i, node);
    return node;
}

map<pair<ll, ll>, int> oc;
pair<ll ,ll > hs[N+2] , hp[N+2] ;

void add(int d, pair<ll, ll> & s, pair<ll, ll> & pr, int c)
{
    pr.first = pr.first * p[0] % m[0] ;
    pr.first = (pr.first + c) % m[0] ;

    pr.second = pr.second * p[1] % m[1] ;
    pr.second = (pr.second + c) % m[1] ;


    s.first = (s.first  +  (c * po[0][d] % m[0] ) ) % m[0] ;
    s.second = (s.second  +  (c * po[1][d] % m[1] ) ) % m[1] ;
}

vector<int> nodes;

bool sol(int i, int len, int d, pair<ll, ll> pr, pair<ll, ll> su, int pa)
{
    if( len < d) return 0;

    nodes.push_back(i) ;

    add( d-1, su, pr, a[i] );

    hs[i] = su;
    hp[i] = pr;

    if(len == d)
    {
        nodes.pop_back();
        return pr == su;
    }
    else if( 2*d >= len )
    {
        int rem = len - d ;
        int id = (int)nodes.size() - rem - 1;

        pair<ll, ll > h_r = hp[nodes[id]];

        h_r.first = h_r.first * po[0][rem] % m[0] ;
        h_r.second = h_r.second * po[1][rem] % m[1] ;

        h_r.first = (pr.first - h_r.first + m[0])%m[0];
        h_r.second = (pr.second - h_r.second + m[1])%m[1];

        if( hp[nodes[id]] == hs[nodes[id]] && oc[h_r] )
        {
            return 1;
        }
    }

    for(int ch : ad[i]) if( processed[ch] != vid && ch != pa) if(sol(ch, len, d+1, pr, su, i)  ) return 1;

    nodes.pop_back();

    return 0;
}

void add(int i, int d, int len, pair<ll, ll> pr, int p , int inc = 1 )
{
    if(len == d) return;

    pair<ll, ll> te = {0,0};
    add( d-1, te, pr, a[i] ) ;

    oc[pr] += inc;

    for(int ch : ad[i]) if(processed[ch] != vid && ch != p) add(ch, d+1 , len, pr , i, inc) ;
}

bool centroid_decomp(int node , int len) {
    int centroid = get_centroid(get_subtree_sizes(node) >> 1, node);

    processed[centroid] = vid ;


    for(int ch : ad[centroid]) if(processed[ch] != vid)
    {
        add(ch, 1, len, {0,0}, 0);
    }

    pair<ll, ll> pr = {0,0}, su = {0,0};

    add(0, pr, su, a[centroid]);
    if(len == 2) return oc[pr] > 0 ;

    nodes.push_back(0);
    nodes.push_back(centroid);
    hp[centroid] = hs[centroid] = pr;

    for(int ch : ad[centroid] ) if( processed[ch] != vid)
    {
        add(ch, 1, len, {0,0}, 0 , -1);

        if( sol(ch, len, 2, pr, su, centroid) )
        {
            return 1;
        }

        add(ch, 1, len, {0,0}, 0, 1);
    }

    nodes.pop_back();

    oc.clear() ;

    for (int i : ad[centroid]) if (processed[i] != vid)
    {
        if( centroid_decomp(i, len)) return 1;
    }



    return 0;
}


int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    hp[0] = {0,0};
    hs[0] = {0,0};

    po[0][0] =1;
    po[1][0] =1;

    for(int i = 1 ; i< N ; i++)
    {
        for (int j = 0; j < 2; ++j) {
            po[j][i] = 1ll*po[j][i-1] * p[j] % m[j] ;
        }
    }



    int n;
    cin >> n;
    for(int i =1 ; i<= n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - 'a' + 1;
    }

    for(int i= 1; i <= n - 1;i++)
    {
        int u , v;
        cin >> u >> v ;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }


    int l = 2 , r = (n+1)/2 , md , ans = 1;
    while (l <= r)
    {
        md = (l+r)/2;

        int len = 2*md - 1;

        vid++ ;
        oc.clear();
        nodes.clear();

        if(centroid_decomp(1, len))
        {
            ans = len , l = md+1 ;
        }
        else r = md-1 ;
    }


    l = 1, r = n/2 ;
    while (l <= r)
    {
        md = (l+r)/2;
        int len = 2*md ;

        vid++ ;
        oc.clear();
        nodes.clear();

        if(centroid_decomp(1, len)) ans = max(ans , len) , l = md+1 ;
        else r = md-1 ;
    }

    cout << ans ;
}
