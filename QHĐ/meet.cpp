#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 9999;
const int oo = 1e9 + 17;

int n, m;
int maxt, maxD;
int a[N][N], dp[N][N], g[N][N];

void solve(void) {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    memset(g, 0, sizeof(g));

    for(int i = 1; i <= n; ++i) {
        dp[i][0] = -oo;
        dp[i][m+1] = -oo;
    }

    for(int j = 1; j <= m; ++j) {
        dp[1][j] = a[1][j];
    }

    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            maxD = -oo;
            if (a[i-1][j-1] < a[i][j]) {
                maxD = max(maxD, dp[i-1][j-1]);
            }
            if (a[i-1][j] < a[i][j]) {
                maxD = max(maxD, dp[i-1][j]);
            }
            if  (a[i-1][j+1] < a[i][j]) {
                maxD = max(maxD, dp[i-1][j+1]);
            }
            dp[i][j] = maxD + a[i][j];
        }
    }

    for(int j = 1; j <= n; ++j) {
        g[j][0] = -oo;
        g[j][m+1] = -oo;
    }

    for(int i = 1; i <= m; ++i) {
        g[n][i] = a[n][i];
    }

    for(int i = n - 1; i >= 1; --i) {
        for(int j = 1; j <= m; ++j) {
            maxt = -oo;
            if (a[i+1][j-1] < a[i][j]) {
                maxt = max(maxt, g[i+1][j-1]);
            }
            if (a[i+1][j] < a[i][j]) {
                maxt = max(maxt, g[i+1][j]);
            }
            if (a[i+1][j+1] < a[i][j]) {
                maxt = max(maxt, g[i+1][j+1]);
            }
            g[i][j] = maxt + a[i][j];
        }
    }

    int res = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            res = max(res, dp[i][j] + g[i][j] - a[i][j]);
        }
    }
    cout << res;
}

signed main(void) {
      fast;
      solve();
      return 0;
}
