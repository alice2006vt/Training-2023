#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1000 + 15;

int n;
int a[N], b[N], dp[N][N];

void solve(void) {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if (!(a[i] + b[j] >= 0)) {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
			else dp[i][j] = max(dp[i-1][j-1] + 1, dp[i-1][j]);
		}
	}

	cout << dp[n][n];
}

signed main(void) {
      fast;
      solve();
      return 0;
}
