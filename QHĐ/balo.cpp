#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 15;

int n;
int result = 0;
int a[N], c[N], dp[N];

void solve(void) {
      cin >> n;
      for(int i = 1; i <= n; ++i) {
            cin >> a[i] >> c[i];
      }

      dp[1] = c[1];

      for(int i = 2; i <= n; ++i) {
            long long maxD = 0;
            for(int j = 1; j <= i - 1; ++j) {
                  if (a[i] > a[j] && maxD < dp[j]) {
                        maxD = dp[j];
                  }
            }
            dp[i] = maxD + c[i];
      }

      for(int i = 1; i <= n; ++i) {
            result = max(result, dp[i]);
      }

      cout << result;
}
signed main(void) {
      solve();
      return 0;
}
