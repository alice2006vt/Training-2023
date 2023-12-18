#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define int long long
#define ii pair <int, int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e6 + 15;

int n;
int result = 0;
int b[N], dp[N];

ii a[N];

bool cmp(ii &x, ii &y) {
      if (x.fi == y.fi) return x.se < y.se;
      else return x.fi < y.fi;
}

void solve(void) {
      cin >> n;

      for(int i = 1; i <= n; ++i) cin >> a[i].fi >> a[i].se;

      sort(a + 1, a + n + 1, cmp);

      for(int i = 1; i <= n; ++i) {
            b[i] = a[i].se - a[i].fi;
      }

      for(int i = 1; i <= n; ++i) {
            long long maxD = b[i];
            for(int j = 1; j <= i - 1; ++j) {
                  if (a[i].fi >= a[j].second && dp[j] + b[i] > maxD) {
                        maxD = dp[j] + b[i];
                  }
            }
            for(int j = 1; j <= i - 1; ++j) {
                  if (a[i].fi <= a[j].se && a[i].se >= a[j].se && dp[j] + a[i].se - a[j].se - (a[j].se - a[i].fi) > maxD) {
                        maxD = dp[j] + a[i].se - a[j].se - (a[j].se - a[i].fi);
                  }
            }
            dp[i] = maxD;
      }

      for(int i = 1; i <= n; ++i) {
            result = max(result, dp[i]);
      }

      cout << result;
}

signed main(void) {
      fast;
      solve();
      return 0;
}
