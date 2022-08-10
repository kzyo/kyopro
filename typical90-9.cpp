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

int main()
{
    ll N;
    cin >> N;

    vector<pos> p(N);
    REP(i, N)
    {
        ll x, y;
        cin >> x >> y;
        p[i] = pos{x, y};
    }

    ld maxRad = -1;
    REP(i, N)
    {
        pos center = p[i];
        vector<ld> rad(N);
        REP(j, N)
        {
            rad[j] = atan2(p[j].x - center.x, p[j].y - center.y);
        }
        rad.erase(rad.begin() + i);
        sort(rad.begin(), rad.end());

        REP(j, N - 1)
        {
            ld one = rad[j];
            ld target = one + M_PI;
            if (target >= 2 * M_PI)
            {
                target -= 2 * M_PI;
            }

            auto cand = upper_bound(rad.begin(), rad.end(), target);
            ll idx = distance(rad.begin(), cand);
            ll idx2 = idx - 1;
            if (idx2 < 0)
            {
                idx2 = rad.size() - 1;
            }

            ld val1 = abs(one - rad[idx]);
            ld val2 = abs(one - rad[idx2]);
            maxRad = max(maxRad, max(val1, val2));
        }
    }

    ld ans = maxRad / M_PI * 180;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    cout << ans << endl;

    return 0;
}