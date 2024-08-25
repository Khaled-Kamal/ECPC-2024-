#include <iostream>
#include <bits/stdc++.h>

#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y, a, b, p;
    vector<vector<int>> b3(2001,vector<int>(7));
    for (int i = 1; i < 2001; i++)
    {
        x = i, b = 0;
        while (x) b3[i][b++] = x%3, x /= 3;
    }
    a = b = 0, p = 1;
    for (int i = 0; i < 7; i++)
    {
        vector<int> s1, s2;
        for (int j = 1; j < 2001; j++)
        {
            if (b3[j][i]==0) s1.push_back(j);
            else if (b3[j][i]==1) s2.push_back(j);
        }
        cout<<'?'<<endl;
        cout<<s1.size()<<endl;
        for (auto &&it : s1) cout<<it<<' '; cout<<endl;
        cout<<s2.size()<<endl;
        for (auto &&it : s2) cout<<it<<' '; cout<<endl;
        cin>>x>>y, x--, y--;
        a += p * x, b += p * y, p *= 3;
    }
    cout<<"! "<<a<<' '<<b<<endl;
    return 0;
}