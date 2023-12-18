#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e6 + 15;

struct info {
    int x, y;
};

int n, k;
int a[N], b[N];

int res = 0, sum = 0;
vector <info> luu;


bool cmp(info a, info b) {
    if (a.x == b.x) return a.y > b.y;
    else return a.x < b.x;
}

void solve(void) {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        luu.push_back({a[i], k});
        cin >> b[i];
        luu.push_back({b[i], -k});
    }

    sort(luu.begin(), luu.end(), cmp);

    for(int i = 0; i < luu.size(); ++i) {
        if (luu[i].y > 0) {
            sum += luu[i].y;
            res = max(res, sum);
        }
        else {
            res = max(res, sum);
            sum += luu[i].y;
        }
    }
    cout << res;
}

signed main(void) {
      fast;
      solve();
      return 0;
}
