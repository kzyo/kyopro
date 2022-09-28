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
    ll N, L;
    cin >> N >> L;

    vector<mint> dp(N + 1);

    dp[0] = 1;
    REP(i, N)
    {
        dp[i + 1] = dp[i];
        if (i + 1 - L >= 0)
        {
            dp[i + 1] += dp[i + 1 - L];
        }
    }

    cout << dp[N].val() << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}