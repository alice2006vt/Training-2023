#include<bits/stdc++.h>

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout.tie(NULL);

using namespace std;

const int N = 999;

int n, m;
int a[N][N], dp[N][N];

void solve(void) {
      cin >> n >> m;

      for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                  cin >> a[i][j];
            }
      }

      for(int i = 1; i <= n; ++i) {
            dp[1][i] = a[1][i];
      }

      for(int i = 2; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                  dp[i][j] = min(dp[i-1][j], a[i][j]);
                  for(int k = 1; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], a[i][k] + dp[i-1][j-k]);
                  }
            }
      }

      cout << dp[m][n] << "\n";
}

signed main(void) {
      fast;
      solve();
      return 0;
}
