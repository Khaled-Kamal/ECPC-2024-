#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
int a[N], b[N], n, A, B;
long long dp[N][2][2];
int na[N], nb[N];
long long solve(int i = 0, int take1 = 0, int take2 = 0) {
    if (i == n) {
        return take1 && take2? 0: -1e12;
    }
    long long& ret = dp[i][take1][take2];
    if (~ret) return ret;
    int i1 = i - take1;
    int i2 = i - take2;
    ret = 1LL * abs(a[i1] - b[i2]) + solve(i + 1, take1, take2);
    if (!take1) {
        ret = max(ret, 1LL * abs(A - b[i2]) + solve(i+1, 1, take2));
    }
    if (!take2) {
        ret = max(ret, 1LL * abs(B - a[i1]) + solve(i+1, take1, 1));
    }
    if (!take1 && !take2) {
        ret = max(ret, 1LL * abs(A - B) + solve(i + 1, 1, 1));
    }
    return ret;
}
void build(int i = 0, int take1 = 0, int take2 = 0) {
    if (i == n) {
        return;
    }

    long long ret = dp[i][take1][take2];
    int i1 = i - take1;
    int i2 = i - take2;
    if (ret == 1LL * abs(a[i1] - b[i2]) + solve(i + 1, take1, take2)) {
        na[i] = a[i1];
        nb[i] = b[i2];
        build(i + 1, take1, take2);
        return;
    }
    if (!take1 && ret == 1LL * abs(A - b[i2]) + solve(i+1, 1, take2)) {
        na[i] = A;
        nb[i] = b[i2];
        build(i + 1, 1, take2);
        return;
    }
    if (!take2 && ret == 1LL * abs(B - a[i1]) + solve(i+1, take1, 1)) {
        na[i] = a[i1];
        nb[i] = B;
        build(i + 1, take1, 1);
        return;
    }
    if (!take1 && !take2 && ret == 1LL * abs(A - B) + solve(i + 1, 1, 1)) {
        na[i] = A;
        nb[i] = B;
        build(i + 1, 1, 1);
        return;
    }
}
int main () {
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n-1; i++) scanf("%d", a+i);
    for (int i = 0; i < n-1; i++) scanf("%d", b+i);
    for (int i = 0; i < n - 1; i++) sum += a[i];
    a[n-1] = b[n-1] = n;
    A = ((1LL * n * (n+1)) / 2) - sum;
    sum = 0;
    for (int i = 0; i < n - 1; i++) sum += b[i];
    B = ((1LL * n * (n+1)) / 2) - sum;
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve());
    build();
    sum = 0;

    for (int i = 0; i < n; i++) {
        sum += na[i];
        sum -= nb[i];
    }
    assert(sum == 0);
    for (int i = 0; i < n; i++)  {
        sum += na[i];
    }
    assert(sum == (1LL * n * (n+1) / 2));
    for (int i = 0; i < n; i++) printf("%d ", na[i]);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", nb[i]);
    printf("\n");

}