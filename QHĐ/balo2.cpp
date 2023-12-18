#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 100005;

int n, W;
vector <int> w(N), c(N);
vector <vector <int>> dp(N, vector <int>(N));

void solve(void) {
      cin >> n >> W;

      for(int i = 1; i <= n; ++i) cin >> w[i] >> c[i];

      for(int i = 0; i <= W; ++i) dp[0][i] = 0;

      for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= W; ++j) {
                  if (w[i] <= j) {
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + c[i]);
                  }
                  else dp[i][j] = dp[i-1][j];
            }
      }

      cout << dp[n][W];
}

signed main(void) {
      fast;
      solve();
      return 0;
}
