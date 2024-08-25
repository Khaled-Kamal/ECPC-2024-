// main solution 
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define int long long
int n, m;
char grid[22][22];
int id[22][22];
vector<tuple<int, int, bool, int, set<int>, int, char>> q;
set<tuple<int, int, bool, int, set<int>>> vis;
//
 
bool move(int i, int j, bool isRight, int mask, set<int> walls, int par, char op) {
    if (i < 1 or i > n or j < 1 or j > m)
        return false;
    if (isupper(grid[i][j]) and grid[i][j] <= 'E')
        mask |= (1 << (grid[i][j] - 'A'));
    if (grid[i][j] == '#' or (grid[i][j] == 'W' and walls.find(i * (m + 1) + j) == walls.end()) or
        !vis.insert({i, j, isRight, mask, walls}).second or
        ((op == 'U' or op == 'D') and (j == 1 or j == m) and isRight == (j == m)))
        return false;
    q.emplace_back(i, j, isRight, mask, walls, par, op);
    return grid[i][j] == 'G';
}
 
void printPath(int u) {
    if (!u) return;
    auto &[i, j, isRight, mask, walls, par, op] = q[u];
    printPath(par);
    cout << op;
}
 
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    int cnt(1);
    for (int j = 1; j <= m; j++) {
        for (int i = n; i >= 1; i--) {
            if (grid[i][j] == 'S' and grid[i - 1][j] == 'S') {
                id[i][j] = id[i - 1][j] = cnt++;
                i--;
                continue;
            }
            if (grid[i][j] <= 'e' and grid[i - 1][j] == grid[i][j]) {
                id[i][j] = id[i - 1][j] = cnt++;
                i--;
                continue;
            }
        }
    }
    q.push_back({n, 1, true, 0, {}, -1, 0});
    vis.insert({n, 1, true, 0, {}});
    for (int f = 0; f < q.size(); f++) {
        auto [i, j, isRight, mask, walls, par, op] = q[f];
        if (move(i, j + isRight * 2 - 1, isRight, mask, walls, f, 'F'))
            break;
        if (move(i, j, !isRight, mask, walls, f, !isRight ? 'R' : 'L'))
            break;
        if (grid[i][j] == 'S' or (islower(grid[i][j]) and ((mask >> (grid[i][j] - 'a')) & 1)))
            for (int d = -1; d < 2; d += 2)
                if (grid[i + d][j] == grid[i][j] and id[i + d][j] == id[i][j])
                    if (move(i + d, j, isRight, mask, walls, f, ~d ? 'D' : 'U'))
                        break;
        if (grid[i][j + isRight * 2 - 1] == 'W') {
            auto st = walls;
            st.insert(i * (m + 1) + j + isRight * 2 - 1);
            if (move(i, j, isRight, mask, st, f, 'B'))
                break;
        }
 
    }
    auto [i, j, isRight, mask, walls, par, op] = q.back();
    if (grid[i][j] == 'G')
        printPath(q.size() - 1);
    else
        cout << "no way";
}