#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const int N = 2e5 + 5;

bool isP(int n) {
	if (n < 2) return 0;
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}
ll n, c = 0, vis[200005], cnt = 0;
vector<vector<ll>>g;
void Dfs(int n) {
	vis[n] = 1;
	for (auto i : g[n])
		if (!vis[i])
			cnt++, Dfs(i);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n; c = n * (n - 1) / 2;
	g = vector<vector<ll>>(n + 1);
	for (int i = 0; i < n - 1; i++) {
		ll u, v; cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
		vis[u] += isP(u);
		vis[v] += isP(v);
	}
	for (int i = 1; i <= n; i++)
	{
		cnt = 1;
		if (!vis[i]) Dfs(i);
		c -= (cnt * (cnt - 1) / 2);
	}
	cout << c;
}