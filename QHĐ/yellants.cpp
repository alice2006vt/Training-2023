#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1111;
const int oo = 1e18;

int n , m;
int res = 0;
int a[N][N], dp[N][N];

void solve(void) {
     cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= m ; ++j) {
			cin >> a[i][j];
		}
	}
    for(int i = 0 ; i <= n + 1 ; ++i) {
        for(int j = 0 ; j <= m + 1 ; ++j) { 
			dp[i][j] = -oo;
		}
	}
    for(int i = 1 ; i <= m ; ++i) {
        dp[1][i] = a[1][i];
	}

    for(int i = 2 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            int t = -oo;
            if(a[i - 1][j - 1] < a[i][j]) t = max(t , dp[i - 1][j - 1]);
            if(a[i - 1][j] < a[i][j]) t = max(t , dp[i - 1][j]);
            if(a[i - 1][j + 1] < a[i][j]) t = max(t , dp[i - 1][j + 1]);
            if(t == -oo) {
				dp[i][j] = -oo;
			}
            else {
				dp[i][j] = t + a[i][j];
			}
            if(i == n) {
				res = max(res , dp[i][j]);
			}
        }    
    }
    cout << res << endl;
}

signed main(void) {
	fast;
    //freopen("yellants.inp" , "r" , stdin);
    //freopen("yellants.out" , "w" , stdout);
 	solve();
    return 0;
}
