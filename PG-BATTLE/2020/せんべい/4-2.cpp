#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint1000000007;

int main()
{
    ll H, W;
    cin >> H >> W;

    if (H % 2 == 1 && W % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    mint dp[H * W + 1][1 << H];
    dp[0][0] = 1;

    for (ll i = 0; i < H * W; i++)
    {
        REP(j, 1 << H)
        {
            if (j & 1)
            {
                dp[i + 1][j >> 1] += dp[i][j];
                continue;
            }
            if (H >= 2 && (j & 0b10) == 0 && (i % H) != (H - 1))
            {
                dp[i + 1][(j >> 1) | 0b01] += dp[i][j];
            }
            dp[i + 1][(j >> 1) | (1 << (H - 1))] += dp[i][j];
        }
        // REP(j, 1 << H)
        // {
        //     if (dp[i][j].val() > 0)
        //     {
        //         cout << i << ", " << j << ": " << dp[i][j].val() << endl;
        //     }
        // }
    }

    cout << dp[H * W][0].val() << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}