#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename key>
using ordered_set = tree<key, null_type,less<key>,rb_tree_tag,tree_order_statistics_node_update>;

void Speed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}



void solve(){
    int n;
    cin >> n;
    priority_queue<pair<int,int>> q;
    ordered_set<int> st;

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        q.push({x,i});
    }

    while(q.size()){
        auto a = q.top(); q.pop();
        int t = a.second;
        a.second -= st.order_of_key(a.second + 1);
        if(a.second % 2){
            cout << "Bakkar\n";
        }else cout << "Rashida\n";
        //cout << a.second << " ~\n";
        st.insert(t);
    }


}

int main()
{
    Speed();
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
