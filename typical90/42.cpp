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
    ll K;
    cin >> K;

    if (K % 9 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    vector dp(K + 1, vector<mint>(K + 1, 0));
    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (ll i = 2; i <= K; i++)
    {
        for (ll j = i; j <= K; j++)
        {
            for (ll k = 1; k <= 9 && j - k > 0; k++)
            {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    mint ans = 0;
    REP(i, K)
    {
        ans += dp[i + 1][K].val();
    }

    cout << ans.val() << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}