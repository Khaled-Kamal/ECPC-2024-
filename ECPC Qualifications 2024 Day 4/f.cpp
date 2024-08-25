#include <iostream>
#define int long long
using namespace std;
void solve()
{
	int n, x, c, xorArr = 0;
	cin >> n >> x;
	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		xorArr ^= arr[i];
	}

	if (xorArr >= x)
		return void(cout << "0");
	int ans = 0;
	for (int j = 31; j >= 0; j--)
	{
		c = 0;
		for (int i = 0; i < n; i++)
		{
			c += (arr[i]& (1LL<<j))!= 0;
		}
		if (c % 2 == 0 and c != n)
		{
			xorArr += (1LL << j);
			ans++;
			if (xorArr >= x)
				return void(cout << ans);
		}
	}
	cout << "-1";
}
signed main()
{
	solve();
}