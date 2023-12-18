#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e6 + 15;

int n, m;
int a[N], b[N];
int res = 0;

vector <int> dp;
vector <bool> check(N);

void sieve(int n) {
	for(int i = 2; i <= n; ++i) {
		check[i] = true;
	}

	for(int i = 2; i <= n; ++i) {
		if (check[i]) {
			for(int j= i * i; j <= n; j += i) {
				check[j] = false;
			}
		}
	}
}

void solve(void) {
	cin >> n;

	sieve(N);

	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i) {
		if (check[a[i]]) b[m++] = a[i];
	}

	dp.push_back(b[m]);
	for(int i = m - 1; i >= 1; --i) {
		if (dp.back() < a[i]) {
			dp.push_back(a[i]);
		}
		else {
			int index = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
			dp[index] = a[i];
		}
	}
	cout << dp.size();
}

signed main(void) {
      fast;
      solve();
      return 0;
}
