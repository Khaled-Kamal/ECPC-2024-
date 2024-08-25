#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct BIT {
    int bit[100001] = {0};
    void add(int e, int v) {
        while (e <= n) {
            bit[e] += v;
            e += e & -e;
        }
    }

    int sum(int e) {
        int su = 0;
        while (e >= 1) {
            su += bit[e];
            e -= e & -e;
        }
        return su;
    }
}bit1,bit2;
long long mod = 1e9+9;
long long fast(long long a,long long b){
    if(b==0)return 1;
    long long h = fast(a,b/2);
    h*=h;h%=mod;
    if(b&1)return (h*a)%mod;
    return h;
}signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    int arr[n+1];
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]<=1){
            bit1.add(i,1);
            if(arr[i]==1)bit2.add(i,fast(2,n-i));
        }
    }
    int q;cin>>q;
    while(q--){
        int ty,l,r;
        cin>>ty>>l>>r;
        if(ty==2){
            int su = bit1.sum(r)-bit1.sum(l-1);
            if(su==r-l+1){
                long long ans = (bit2.sum(r)-bit2.sum(l-1)+mod)%mod;
                ans*=fast(fast(2,n-r),mod-2);ans%=mod;
                cout<<ans<<endl;
            }else{
                cout<<"Impossible"<<endl;
            }
        }else{
            if(arr[l]>1){
                bit1.add(l,1);
            }
            if(arr[l]==1){
                bit2.add(l,(-fast(2,n-l)+mod)%mod);
            }
            arr[l] = ((arr[l]^r)&1);
            if(arr[l]==1){
                bit2.add(l,fast(2,n-l));
            }
        }
    }
    return 0;
}