#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 999;

int n;
int dp[N];

void solve(void) {
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
}

signed main(void) {
      fast;
      solve();
      return 0;
}

