#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1000000;

int n;
int a[N], dp[N];

void solve(void) {
      cin >> n;
      for(int i = 0; i < n ; ++i) {
            cin >> a[i];
      }

      dp[0] = a[0];
      dp[1] = max(a[0] + a[1], a[1]);
      dp[2] = max(a[0] + a[2], max(a[1] + a[2], a[2]));
	  dp[3] = max({a[0] + a[3], a[1] + a[3], a[3], a[0] + a[1] + a[3], a[0] + a[2] + a[3]});
      for(int i = 3; i < n; ++i) {
         dp[i] = max(dp[i-2] + a[i], max(dp[i-3] + a[i], max(dp[i-4] + a[i-1] + a[i], dp[i-3] + a[i-1] + a[i])));
      }

      cout << max(dp[n-1], max(dp[n-2], dp[n-3])) << '\n';

}

signed main(void) {
      solve();
      return 0;
}
