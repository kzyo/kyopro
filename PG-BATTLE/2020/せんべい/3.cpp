#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

vector<vector<char>> MAP;
ll ans = 0;

ll dy[] = {-1, 0, 1, 0};
ll dx[] = {0, -1, 0, 1};

bool solve(ll x, ll y, ll ex, ll ey, ll dir)
{
    if (ans > 10000000)
        return false;
    if (x == ex && y == ey)
        return true;
    ans++;

    cout << x << ',' << y << ',' << dir << endl;

    if (MAP[y + dy[(dir + 1) % 4]][x + dx[(dir + 1) % 4]] == '.')
    {
        y = y + dy[(dir + 1) % 4];
        x = x + dx[(dir + 1) % 4];
        dir += 1;
        dir %= 4;
        return solve(x, y, ex, ey, dir);
    }

    if (MAP[y + dy[dir]][x + dx[dir]] == '.')
    {
        y = y + dy[dir];
        x = x + dx[dir];
        return solve(x, y, ex, ey, dir);
    }

    if (MAP[y + dy[(dir + 3) % 4]][x + dx[(dir + 3) % 4]] == '.')
    {
        y = y + dy[(dir + 3) % 4];
        x = x + dx[(dir + 3) % 4];
        dir += 3;
        dir %= 4;
        return solve(x, y, ex, ey, dir);
    }

    if (MAP[y + dy[(dir + 2) % 4]][x + dx[(dir + 2) % 4]] == '.')
    {
        y = y + dy[(dir + 2) % 4];
        x = x + dx[(dir + 2) % 4];
        dir += 2;
        dir %= 4;
        return solve(x, y, ex, ey, dir);
    }

    return false;
}

int main()
{
    ll H, W;
    cin >> H >> W;
    MAP = vector(H + 2, vector<char>(W + 2, '#'));

    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;

    REP(i, H)
    {
        string s;
        cin >> s;
        REP(j, W)
        {
            MAP[i + 1][j + 1] = s[j];
        }
    }

    if (solve(py, px, qy, qx, 0))
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}