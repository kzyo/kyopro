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
        tasks[i + 1] = task{d, c, s};
    }
    sort(tasks.begin(), tasks.end(), [](task a, task b)
         { return a.d < b.d; });

    vector dp(5001, vector<ll>(5001, 0));
    REP(day, 5001)
    {
        if (day > 0)
        {
            for (int doTask = 0; doTask <= N; doTask++)
            {
                dp[day][doTask] = max(dp[day][doTask], dp[day - 1][doTask]);
            }
        }

        for (int doTask = 1; doTask <= N; doTask++)
        {

            task t = tasks[doTask];
            REP(doneTask, doTask)
            {
                if (day + t.c <= t.d)
                {
                    dp[day + t.c][doTask] = max(dp[day + t.c][doTask], dp[day][doneTask] + t.s);
                }
            }
        }
    }

    ll ans = 0;
    REP(i, N + 1)
    {
        ans = max(ans, dp[5000][i]);
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}