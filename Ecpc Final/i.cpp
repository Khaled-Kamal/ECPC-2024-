#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
string s;
vector<int> a;
bool check(int l, int r){
	bool flag=1;
	for(int i=l,j=r; i<=j; i++,j--) if(s[i]!=s[j]) flag=0;
	int sum = 0,cur=0;
	for(int i=l; i<=r; i++) sum+=a[i], cur|=a[i];
	flag &= (cur==sum);
	return flag;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    	cin>>n>>s;
    	a = vector<int>(n);
    	for(auto &i:a) cin>>i;
    	int ans = 1;
    	for(int len = 30; len>1; len--){
    		for(int i=0; i<n-len+1; i++){
    			if(check(i,i+len-1)) {ans =len;  len = -10; break;}
    		}
    	} 
    	cout<<ans<<endl;
    }
}