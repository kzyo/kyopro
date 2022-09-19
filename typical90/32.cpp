#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

int main()
{
    ll N;
    cin >> N;

    vector a(N, vector<ll>(N));
    REP(i, N)
    REP(j, N)
    {
        cin >> a[i][j];
    }

    ll M;
    cin >> M;
    vector ok(N, vector<bool>(N, true));
    REP(i, M)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        ok[x][y] = false;
        ok[y][x] = false;
    }

    vector<ll> p(N);
    REP(i, N)
    p[i] = i;

    ll ans = LLONG_MAX;
    do
    {
        ll cand = a[p[0]][0];
        bool nxt = false;
        for (ll i = 1; i < N; i++)
        {
            if (!ok[p[i - 1]][p[i]])
            {
                nxt = true;
                break;
            }
            cand += a[p[i]][i];
        }
        if (nxt)
            continue;

        ans = min(ans, cand);

    } while (next_permutation(p.begin(), p.end()));

    if (ans == LLONG_MAX)
        ans = -1;

    cout << ans << endl;

    cout
        << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}