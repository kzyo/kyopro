#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

struct task
{
    int d, c, s;
};

int main()
{
    int N;
    cin >> N;

    vector<task> tasks(N + 1);
    REP(i, N)
    {
        int d, c, s;
        cin >> d >> c >> s;
        tasks[i] = task{d, c, s};
    }
    tasks[N] = task{0, 0, 0};
    sort(tasks.begin(), tasks.end(), [](task a, task b) { return a.d < b.d; });

    vector dp(N + 1, vector<ll>(5001, 0));
    for (int doTask = 1; doTask <= N; doTask++)
    {
        task t = tasks[doTask];
        REP(consumedTime, 5001)
        {
            if (consumedTime > 1)
                dp[doTask - 1][consumedTime] = max(dp[doTask - 1][consumedTime], dp[doTask - 1][consumedTime - 1]);
            if (consumedTime <= t.d && consumedTime - t.c >= 0)
            {
                dp[doTask][consumedTime] = max(dp[doTask - 1][consumedTime - t.c] + t.s, dp[doTask - 1][consumedTime]);
            }
            else
            {
                dp[doTask][consumedTime] = dp[doTask - 1][consumedTime];
            }
        }
    }

    ll ans = 0;
    REP(i, 5001)
    {
        ans = max(ans, dp[N][i]);
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}