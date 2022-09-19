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
    ll N, M;
    cin >> N >> M;

    vector<ll> a(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    vector dp(M + 1, vector<ll>(N + 1, LLONG_MIN));
    REP(i, N + 1)
    dp[0][i] = 0;

    for (ll i = 1; i <= M; i++)
    {
        for (ll j = i; j <= N; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + a[j - 1] * i);
        }
    }

    cout << dp[M][N] << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}