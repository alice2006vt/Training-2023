#include<bits/stdc++.h>

using namespace std;

const int N = 999;

int n, s;
int w[N], c[N];
long long dp[N][N];

void solve(void) {
      cin >> n >> s;

      for(int i = 1; i <= n; ++i) {
            cin >> w[i] >> c[i];
      }

      for(int i = 1; i <= s; ++i) {
            dp[0][i] = 0;
      }

      for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= s; ++j) {
                  dp[i][j] = dp[i-1][j];
                  for(int k = 1; k <= j / w[i]; ++k) {
                        dp[i][j] = max(dp[i][j], dp[i-1][j-k * w[i]] + k * c[i]);
                  }
                  cout << dp[i][j] << " ";
                  cout << '\n';
            }
      }
      cout << dp[n][s] << '\n';
}

signed main(void) {
      solve();
      return 0;
}
