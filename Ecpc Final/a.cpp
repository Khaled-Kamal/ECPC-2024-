#include<bits/stdc++.h>
using namespace std;
#define L '\n'
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
 
int main() {
    ll n,x,y; cin >> n >> x >> y;
    ll sum = x * ((n*(n+1))/2);
    cout << "? 1 " << n;
    for (int i = 0; i < n; ++i) {
        cout << " " << i+1;
    }
    cout << endl;
    cout.flush();
    ll ret; cin >> ret;
    cout << "! " << (sum-ret)/(x-y);
    return 0;
}