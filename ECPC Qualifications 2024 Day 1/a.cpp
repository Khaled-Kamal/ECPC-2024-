#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct st {
    st *l = 0, *r = 0;
    int mul = 0;

    ~st() {
        if(l) delete l, delete r;
    }

    void create() {
        if(!l) {
            l = new st, r = new st;
        }
    }

    void plus(int lx, int rx, int i, int val) {
        if(i < lx || i > rx) return;
        if(lx == rx)
            return void(mul += val);
        create();
        int mid = lx + rx >> 1;
        l->plus(lx, mid, i, val), r->plus(mid + 1, rx, i, val);
        mul = l->mul * 1LL * r->mul % mod;
    }
    int get(int lx, int rx, int L, int R) {
        if(L > rx || R < lx) return 1;
        if(lx >= L && rx <= R) return mul;
        create();
        int mid = lx + rx >> 1;
        return l->get(lx, mid, L, R) * 1LL * r->get(mid + 1, rx, L, R) % mod;
    }
};

void TC() {
    int n, q;
    cin >> n >> q;
    st freq;
    vector<int> arr(n);
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        arr[i] = x;
        freq.plus(1, 1e9, x, 1);
    }
    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1) {
            freq.plus(1, 1e9, arr[l - 1], -1);
            arr[l - 1] = r;
            freq.plus(1, 1e9, arr[l - 1], 1);
        }
        else {
            cout << freq.get(1, 1e9, l, r) << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int test = 1; test <= tc; ++test) {
        TC();
    }
//    cerr << clock() / 1000.0 << " Secs";
    return 0;
}
