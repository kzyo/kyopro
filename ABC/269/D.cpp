#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

const ll M = 2010;
bool m[M][M];
bool visited[M][M];

ll ans = 0;
void solve(ll i, ll j, bool ok)
{
    if (visited[i][j] == true || m[i][j] == false)
        return;

    visited[i][j] = true;
    if (ok)
        ans++;
    solve(i - 1, j - 1, false);
    solve(i, j - 1, false);
    solve(i - 1, j, false);
    solve(i + 1, j + 1, false);
    solve(i + 1, j, false);
    solve(i, j + 1, false);
    return;
}

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        ll x, y;
        cin >> x >> y;
        x += 1000;
        y += 1000;
        m[x][y] = true;
    }

    REP(i, M)
    REP(j, M)
    solve(i, j, true);

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}