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

    ll A[N];
    REP(i, N)
    {
        ll a;
        cin >> a;
        A[i] = a;
    }

    mint ans = 0;
    for (int i = 1; i <= N; i++)
    {
        vector dp(103, vector(103, vector<mint>(103, 0)));
        dp[0][0][0] = 1;

        for (int j = 0; j <= N; j++)
        {
            REP(k, i + 1)
            {
                REP(l, i)
                {
                    dp[j + 1][k][l] += dp[j][k][l];
                    if (k != i)
                        dp[j + 1][k + 1][(l + A[j]) % i] += dp[j][k][l];
                }
            }
        }
        ans += dp[N][i][0];
    }
    cout << ans.val() << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}