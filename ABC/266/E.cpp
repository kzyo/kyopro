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
    vector<ll> pat(7, 1);
    ll N;
    cin >> N;
    vector<ld> exp(N);
    ll total = pat[6] + pat[5] + pat[4] + pat[3] + pat[2] + pat[1];
    ll ans1 = pat[6] * 6 + 5 * pat[5] + 4 * pat[4] + 3 * pat[3] + 2 * pat[2] + pat[1];
    exp[0] = (ld)ans1 / total;
    REP(i, N - 1)
    {
        pat[6] = 6 * pat[6] + pat[5] + pat[4] + pat[3] + pat[2] + pat[1];
        pat[5] = 5 * pat[5] + pat[4] + pat[3] + pat[2] + pat[1];
        pat[4] = 4 * pat[4] + pat[3] + pat[2] + pat[1];
        pat[3] = 3 * pat[3] + pat[2] + pat[1];
        pat[2] = pat[1] + 2 * pat[2];
        pat[1] = pat[1];

        total = pat[6] + pat[5] + pat[4] + pat[3] + pat[2] + pat[1];
        ans1 = pat[6] * 6 + 5 * pat[5] + 4 * pat[4] + 3 * pat[3] + 2 * pat[2] + pat[1];
        exp[i + 1] = (ld)ans1 / total;
    }

    vector dp(N, vector<ll>(7, 1));
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j < exp[N - i - 1])
            {
                for (int k = 1; k <= 6; k++)
                {
                    dp[i][k]++;
                }
            }
            else
            {
                dp[i][j] += 6;
            }
        }
    }

    total = 0;
    REP(i, 6)
    {
        total += dp[N - 1][i + 1];
    }
    ans1 = dp[N - 1][6] * 6 + 5 * dp[N - 1][5] + 4 * dp[N - 1][4] + 3 * dp[N - 1][3] + 2 * dp[N - 1][2] + dp[N - 1][1];

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    cout << (ld)ans1 / total << endl;

    return 0;
}