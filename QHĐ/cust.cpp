#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e5 + 15;

struct info{
    int x, y;
};
int n;
int l[N], r[N];

bool cmp(info a, info b) {
    return a.x < b.x;
}

info a[N];
int res = 0, index =0 ;
priority_queue <int, vector <int>, greater <int>> q;

void solve(void) {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
    }

    sort(a + 1, a + n + 1, cmp);

    for(int i = 1; i <= n; ++i) {
        while (q.size() && q.top() <= a[i].x) {
            q.pop();
        }
        q.push(a[i].y);
        if (q.size() > res) {
            res = q.size();
            index = a[i].x;
        }
    }
    cout << index << ' ' << res;
}

signed main(void) {
      fast;
      solve();
      return 0;
}
