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

    vector<mint> dp(K + 1, 0);
    dp[0] = 1;
    REP(i, K)
    {
        REP(j, 9)
        {
            ll k = i - j;
            if (k < 0)
                break;
            dp[i + 1] += dp[k];
        }
    }

    cout << dp[K].val() << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}