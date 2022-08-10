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
    int N;
    cin >> N;

    int A[N];
    REP(i, N)
    {
        cin >> A[i];
    }

    mint ans = 0;
    for (int i = 1; i <= N; i++)
    {
        vector dp(N + 1, vector(N + 1, vector<mint>(N, 0)));
        dp[0][0][0] = 1;

        REP(j, N)
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

        // REP(j, N + 1)
        // {
        //     REP(k, i + 1)
        //     REP(l, i)
        //     {
        //         printf("%d, %d, %d = %d", j, k, l, dp[j][k][l]);
        //         cout << endl;
        //     }
        // }

        ans += dp[N][i][0];
    }

    cout << ans.val() << endl;
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}