#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 999;
const int W = 1e5 + 15;

int n, s;
int a[N];
int dp[N][W];

void solve(void) {
	cin >> n >> s;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	for(int j = 0; j <= s; ++j) {
		if (a[1] <= j) {
			dp[1][j] = a[1];
		}
		else dp[1][j] = 0;
	}

	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j <= s; ++j) {
			if (a[i] > j) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]] + a[i]);
			}
		}
	}
	
	cout << dp[n][s];
}

signed main(void) {
      fast;
      solve();
      return 0;
}
