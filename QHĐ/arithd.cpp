#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int N = 1000000;

int n, k;
int a[N];
long long result = 0, dp[N];

void solve(void) {
	  freopen("gift.inp", "r", stdin);
	  freopen("gift.out", "w", stdout);
      cin >> n >> k;

      for(int i = 1; i <= n; ++i) {
            cin >> a[i];
      }

      dp[1] = 1;
      for(int i = 2; i <= n; ++i) {
            long long maxd = 0;
            for(int j = 0; j <= i - 1; ++j) {
                  if (a[i] - a[j] == k && maxd < dp[j]) {
                        maxd = dp[j];
                  }
            }
            dp[i] = maxd + 1;
      }
      
	  for(int i = 1; i <= n; ++i) {
		  result = max(result, dp[i]);
	  }
	  cout << result << '\n';
}

signed main(void) {
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
      solve();
      return 0;
}
