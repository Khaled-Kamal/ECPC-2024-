#include <bits/stdc++.h>
using namespace std;
int main() {
    int n , m; cin >> n >> m;
    const int N = n * m;
    char g[N];
    for(int i = 0; i < N;  ++i) cin >> g[i];
    vector<int> dis(N , -1);
    dis[0] = 1;
    queue<int> q;
    q.push(0);
    auto upd = [&](int u , int v){
        if(v < 0 || v >= N) return;
        if(dis[v] == -1){
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    };
    while(q.size()){
        int u = q.front(); q.pop();
        if(g[u] == '.') upd(u , u + 1);
        else if(g[u] == '#') upd(u , u - 2);
        else{
            upd(u , u + 1);
            upd(u , u + g[u] - '0');
        }
    }
    cout << (~dis[N - 1] ? dis[N - 1] - 1 : -1);
}
