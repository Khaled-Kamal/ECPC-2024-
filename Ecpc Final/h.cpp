#include<iostream>
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 3e5 + 6, mod = 1e9 + 7;

int orTree[N << 2];
vector<pair<int, int>> basisTree[N << 2];
vector<pair<int,int>> mergeBasis(vector<pair<int,int>> a, vector<pair<int,int>> b) {
     for(auto p : b) {
        int val = p.second;
        for(auto x : a) val = min(val, val ^ x.first);
        if(val) a.push_back({val,p.second});
    }
    return a;
}
int a[N], n, q;
void build(int node, int s, int e) {
    basisTree[node].clear();
    if(s==e) {
        orTree[node] = a[s];
        basisTree[node] = {{a[s], a[s]}};
        return;
    }
    int md = (s + e) >> 1;
    build(node<<1,s,md);
    build(node<<1|1,md+1,e);
    orTree[node] = orTree[node << 1] | orTree[node << 1 | 1];
    basisTree[node] = mergeBasis(basisTree[node << 1], basisTree[node << 1 | 1]);
}
void update(int node, int s, int e, int index, int val) {
    if(s==e) {
        orTree[node] = val;
        basisTree[node] = {{val, val}};
        return;
    }
    int md = (s + e) >> 1;
    if(index <= md)
        update(node<<1,s,md,index,val);
    else
        update(node<<1|1,md+1,e,index,val);
    orTree[node] = orTree[node << 1] | orTree[node << 1 | 1];
    basisTree[node] = mergeBasis(basisTree[node << 1], basisTree[node << 1 | 1]);
}
void pruneTree(int node, int s, int e, int l, int r, int val) {
    if(r < s || e < l) return;
    if((orTree[node] & val) == orTree[node])return;
    if(s==e) {
        orTree[node] &= val;
        basisTree[node] = {{orTree[node], orTree[node]}};
        return;
    }
    int md = (s + e) >> 1;
    pruneTree(node<<1,s,md,l,r,val);
    pruneTree(node<<1|1,md+1,e,l,r,val);
    orTree[node] = orTree[node << 1] | orTree[node << 1 | 1];
    basisTree[node] = mergeBasis(basisTree[node << 1], basisTree[node << 1 | 1]);
}
vector<pair<int, int>> query(int node, int s, int e, int l, int r) {
    if(l<=s&&e<=r) return  basisTree[node];
    int md = (s + e) >> 1;
    if(r <= md) return query(node<<1,s,md,l,r);
    else if(l > md) return query(node<<1|1,md+1,e,l,r);
    return mergeBasis(query(node<<1,s,md,l,r),
                      query(node<<1|1,md+1,e,l,r));
}

void doWork() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while (q--) {
        int tp,l,r;
        cin >> tp >> l >> r;
        if(tp==1) {
            int x;
            cin >> x;
            pruneTree(1,1,n,l,r,x);
        }   else if(tp==2) {
            update(1,1,n,l,r);
        }   else {
            auto p = query(1,1,n,l,r);
            int ans = 0;
            for(auto x : p)ans = max(ans, x.first ^ ans);
            cout << ans << '\n';
        }
    }
}

int main() {
    IO
    int t = 1;

    cin >> t;

//    return 0;
    for (int i = 1; i <= t; i++) {
        //  cout << "Case #" << i << ": ";
        doWork();
    }
}
// 6 4 3 1 2