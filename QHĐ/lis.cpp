#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 2999;

int n;
int a[N], dp[N];

int res = 0;

void solve(void) {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	for(int i = 1; i <= n; ++i) {
		int maxD = 0;
		for(int j = 1; j <= i-1; ++j) {
			if (a[i] <= a[j] && dp[j] > maxD) {
				maxD = dp[j];
			}
		}
		dp[i] = maxD + 1;
	}

	for(int i = 1; i <= n; ++i) {
		res = max(res, dp[i]);	
	}
	cout << res;
}
signed main(void) {
	fast;
	solve();
	return 0;
}
