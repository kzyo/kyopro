#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

int main()
{
    int n, sx, sy, tx, ty;
    cin >> n >> sx >> sy >> tx >> ty;

    vector<vector<int>>  circles;
    int x, y, r;
    REP(i, n) {
        cin  >> x >> y >> r;
        circles.push_back(vector<int>{x, y, r});
    }

    int start = -1, end = -1;
    dsu d(n);
    vector<int> circle;
    REP(i, n) {
        circle = circles[i];
        x = circle[0];
        y = circle[1];
        r = circle[2];

        if (hypot(x-sx, y-sy) == (double)r) { start = i;}
        if (hypot(x-tx, y-ty) == (double)r) { end = i;}

        for(long long j = i+1; j < (n); j++) {
            vector<int> circle2 = circles[j];
            int x2 = circle2[0];
            int y2 = circle2[1];
            int r2 = circle2[2];

            ld dist = hypotl(x2 - x, y2 - y);
            if (abs(r - r2) <= dist && dist <= r + r2) {
                d.merge(i, j);
            }
        }
    }
    
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示

    if (d.leader(start) == d.leader(end)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}