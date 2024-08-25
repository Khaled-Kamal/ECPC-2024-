#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;

void Tamora() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

}

const ll mod = 1e9 + 7, inf = 1e9 + 5, N = 5e3 + 5, M = 1e4 + 7, LG = 25, P1 = 37, P2 = 31;

struct State {
    int last, len, lastFreq, mul, diff;
    int par;

};

string ans[N];
bool need[N];
set<int> rem;

void pre() {
    vector<State> q;

    State init = {0, 1, 1, 1, 1, -1};
    q.push_back(init);
    State cur;
    for (int i = 0;; i++) {
        cur = q[i];
        if (cur.diff <= 5e3 && need[cur.diff]) {
            string res;
            auto temp = cur;
            res += char(cur.last + 'a');
            while (cur.par != -1) {
                cur = q[cur.par];
                res += char(cur.last + 'a');
            }
            reverse(all(res));
            cur = temp;
            ans[cur.diff] = res;
            need[cur.diff] = false;
            rem.erase(cur.diff);
            if (rem.empty())return;
        }
        State nxt = cur;
        nxt.par = i;
        nxt.len++;

        nxt.diff += cur.mul - (cur.len - cur.lastFreq + 1);
        nxt.lastFreq++;
        if (nxt.diff <= 5e3)
            q.push_back(nxt);
        nxt.diff -= cur.mul - (cur.len - cur.lastFreq + 1);
        nxt.lastFreq--;

        nxt.last++;
        nxt.mul *= (cur.lastFreq + 1);
        nxt.lastFreq = 1;
        nxt.diff += nxt.mul - nxt.len;
        if (nxt.diff <= 5e3)
            q.push_back(nxt);
    }

}

void solve() {
    int q;
    cin >> q;
    vector<int> ask(q);
    for (int i = 0; i < q; i++) {
        cin >> ask[i];
        need[ask[i]] = true;
        rem.insert(ask[i]);
    }
    pre();
    for (int i = 0; i < q; i++) {
        cout << ans[ask[i]] << endl;
    }
}

int main() {
    Tamora();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
    return 0;//
}