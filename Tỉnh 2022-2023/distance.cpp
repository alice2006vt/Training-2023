#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e5 + 15;

int n;

struct info {
    int x, y;
};

int sqr(int n) {
    return n * n;
}

long double ct(info a, info b) {
    return (long double) sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

info a[N];
long double kq = -1e18;
int max1 = -1e18, max2 = -1e18;
int min1 = 1e18, min2 = 1e18;

vector <info> dist;
bool checkx = false, checky = false;

void solve(void) {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
    }

    for(int i = 1; i <= n; ++i) {
        if (a[i].y == 0) {
            max1 = max(max1, a[i].x);
            min1 = min(min1, a[i].x);
            checkx = true;
        }
        if (a[i].x == 0) {
            max2 = max(max2, a[i].y);
            min2 = min(min2, a[i].y);
            checky = true;
        }
    }

    if (checkx) {
        dist.push_back({max1, 0});
        dist.push_back({min1, 0});
    }
    if (checky) {
        dist.push_back({0, max2});
        dist.push_back({0, min2}); 
    }

    for(int i = 0; i < dist.size(); ++i) {
        for(int j = i + 1; j < dist.size(); ++j) {
            kq = max(kq, ct(dist[i], dist[j]));
        }
    }
    cout << setprecision(5) << fixed << kq;
}

signed main(void) {
      fast;
      solve();
      return 0;
}
