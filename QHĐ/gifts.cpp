#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e6 + 15;

int n;
int a[N], dp[N];

void solve(void) {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    dp[1] = a[1];
    dp[2] = max({a[1] + a[2], a[2]});
    dp[3] = max({a[1] + a[3], a[2] + a[3], a[3]});
    dp[4] = max({a[1] + a[4], a[2] + a[4], a[1] + a[2] + a[4], a[1] + a[3] + a[4], a[4]});
    for(int i = 4; i <= n; ++i) {
        dp[i] = max({dp[i-4] + a[i] + a[i-1], dp[i-3] + a[i], dp[i-2] + a[i], dp[i-3] + a[i-1] + a[i]x});
    }
    cout << max({dp[n-1], dp[n], dp[n-2]});
}

signed main(void) {
      fast;
      solve();
      return 0;
}
