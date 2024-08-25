#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(s) (int)(s).size()
#define all(s) s.begin(),s.end()

void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int M = 1e9 + 7;
int add(int a, int b){
    return (a + b) % M;
}
int mul(int a, int b){
    return 1ll * a * b % M;
}


struct Node {
    int sum_a = 0, sum_a_sq = 0, sum_a_cb = 0;
    int lazy_x = 0;
} neutral;

struct segtree {
    segtree *left = nullptr, *right = nullptr;

    Node node = {};

    int start, end;

    segtree(int l = 0, int r = 0) : start(l), end(r) {}

    void extend() {
        if (left == nullptr) {
            int mid = start + end >> 1;
            left = new segtree(start, mid);
            right = new segtree(mid + 1, end);
        }
    }

    Node pushup(Node a, Node b) {
        Node ret;
        ret.sum_a = add(a.sum_a, b.sum_a);
        ret.sum_a_sq = add(a.sum_a_sq, b.sum_a_sq);
        ret.sum_a_cb = add(a.sum_a_cb, b.sum_a_cb);
        return ret;
    }

    void pushdown() {
        int len = end - start + 1;
        int x = node.lazy_x, x_sq = mul(x, x), x_cb = mul(x, x_sq);
        {
            int temp = mul(mul(3, x), node.sum_a_sq);
            temp = add(temp, mul(mul(3, node.sum_a), x_sq));
            temp = add(temp, mul(len, x_cb));
            node.sum_a_cb = add(node.sum_a_cb, temp);
        }

        {
            int temp = mul(mul(2, node.sum_a), x);
            temp = add(temp, mul(len, x_sq));
            node.sum_a_sq = add(node.sum_a_sq, temp);
        }

        {
            node.sum_a = add(node.sum_a, mul(len, x));
        }
        

        if (start != end) {
            extend();
            left->node.lazy_x = add(left->node.lazy_x, x);    
            right->node.lazy_x = add(right->node.lazy_x, x);
        }
        node.lazy_x = 0;
    }

    void build(vector<int>& v) {
        if (start == end) {
            node.sum_a = v[start];
            node.sum_a_sq = mul(v[start], v[start]);
            node.sum_a_cb = mul(node.sum_a, node.sum_a_sq);
            return;
        }
        extend();
        left->build(v);
        right->build(v);
        node = pushup(left->node, right->node);
    }
    
    void update(int l, int r, int val) {
        pushdown();
        if (start > r || end < l)
            return;
        if (start >= l && end <= r) {
            node.lazy_x = val;
            pushdown();
            return;
        }
        extend();
        left->update(l, r, val);
        right->update(l, r, val);
        node = pushup(left->node, right->node);
    }

    Node query(int l, int r) {
        pushdown(); 
        if (r < start || end < l)
            return neutral;
        if (l <= start && end <= r)
            return node;
        extend();
        Node ret = pushup(left->query(l , r), right->query(l , r));
        return ret;
    }

    ~segtree() {
        if (left == nullptr)return;
        delete left;
        delete right;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto& it : a) cin >> it;

    segtree* root = new segtree(0, n - 1);
    root->build(a);

    int q; cin >> q;
    while(q--){
        int t, l, r; cin >> t >> l >> r;
        l--; r--;
        if(t == 1){
            int x; cin >> x;
            root->update(l, r, x);
        }
        else{
            cout << root->query(l, r).sum_a_cb << '\n';
        }
    }
}

int main() {
    Speed();
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}