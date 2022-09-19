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
    vector<ll> a(2 * N);
    REP(i, 2 * N)
    {
        cin >> a[i];
    }

    vector dp(2 * N, vector<ll>(2 * N));
    REP(i, 2 * N)
    {
        dp[i][i + 1] = abs(a[i] - a[i + 1]);
    }

    for (ll w = 4; w <= 2 * N; w += 2)
    {
        for (ll i = 0; i < 2 * N - w + 1; i++)
        {
            dp[i][i + w - 1] = dp[i + 1][i + w - 2] + abs(a[i] - a[i + w - 1]);
            for (ll j = 2; j <= w - 2; j += 2)
            {
                dp[i][i + w - 1] = min(dp[i][i + w - 1], dp[i][i + j - 1] + dp[i + j][i + w - 1]);
            }
        }
    }

    cout << dp[0][2 * N - 1] << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}