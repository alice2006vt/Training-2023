#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 999;

int n, m;
string dp[N][N];

string add(string a, string b) {
    string res = "";
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;
    int pre = 0;
    for(int i = a.size() - 1; i >= 0; --i) {
        int tmp = a[i] - 48 + b[i] - 48 + pre;
        pre = tmp / 10;
        tmp %= 10;
        res = (char)(tmp + 48) + res;
    }
    if (pre > 0) res = "1" + res;
    return res;
}

void solve(void) {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) dp[1][i] = "1";
    for(int i = 1; i <= n; ++i) dp[i][1] = "1";

    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= m; ++j) {
            dp[i][j] = add(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m];
}

signed main(void) {
      fast;
      solve();
      return 0;
}
