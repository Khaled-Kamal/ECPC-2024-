#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
const int N=1e6+5,mod=1e9+7;
int modPow(int a,int b){
    int ret=1;
    while(b){
        if(b&1)
            ret=1ll*ret*a%mod;
        b>>=1,a=1ll*a*a%mod;
    }
    return ret;
}
int p[N],fac[N],inv[N];
vector<int>primes;
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for (int i = 2; i < N; ++i) {
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=modPow(fac[i],mod-2);
    }
    for (int i = 2; i < N; ++i) {
        if(!p[i])continue;
        primes.push_back(i);
        for (int j = i+i; j < N; j+=i) {
            p[j]=0;
        }
    }
}

int nCr(int n,int r){
    return  1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
void solve(int _t) {
    int n;cin>>n;
    int ans=0;
    for(auto &r:primes){
        if(r>n)break;
        ans=(ans+nCr(n,r))%mod;
    }
    cout<<ans;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    fill(p,p+N,1);
    pre();
    cin >> _t;

    for (int i = 1; i <= _t; ++i)
        solve(i), cout << '\n';
    return 0;
}