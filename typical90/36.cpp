#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

struct pos
{
    ll x;
    ll y;
};

ll dist(pos p, pos pp)
{
    return abs(p.x - pp.x) + abs(p.y - pp.y);
}

int main()
{
    ll N, Q;
    cin >> N >> Q;

    vector<pos> ps(N + 1);
    REP(i, N)
    {
        ll X, Y;
        cin >> X >> Y;
        ps[i + 1] = pos{x : X, y : Y};
    }

    ll maxX = LLONG_MIN;
    ll maxY = LLONG_MIN;
    ll minX = LLONG_MAX;
    ll minY = LLONG_MAX;
    ll maxpos[] = {-1, -1, -1, -1};
    vector<pos> ps45(N + 1);
    REP(i, N)
    {
        pos p = ps[i + 1];
        ps45[i + 1] = pos{x : p.x - p.y, y : p.x + p.y};
        if (ps45[i + 1].x > maxX)
        {
            maxX = ps45[i + 1].x;
            maxpos[0] = i + 1;
        }
        if (minX > ps45[i + 1].x)
        {
            minX = ps45[i + 1].x;
            maxpos[1] = i + 1;
        }
        if (maxY < ps45[i + 1].y)
        {
            maxY = ps45[i + 1].y;
            maxpos[2] = i + 1;
        }
        if (minY > ps45[i + 1].y)
        {
            minY = ps45[i + 1].y;
            maxpos[3] = i + 1;
        }
    }

    REP(i, Q)
    {
        ll idx;
        cin >> idx;
        pos p = ps45[idx];
        ll ans = 0;
        ans = max(ans, dist(ps[idx], ps[maxpos[0]]));
        ans = max(ans, dist(ps[idx], ps[maxpos[1]]));
        ans = max(ans, dist(ps[idx], ps[maxpos[2]]));
        ans = max(ans, dist(ps[idx], ps[maxpos[3]]));

        cout << ans << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}