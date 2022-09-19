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
    ll total = pat[6] + pat[5] + pat[4] + pat[3] + pat[2] + pat[1];
    ll ans1 = pat[6] * 6 + 5 * pat[5] + 4 * pat[4] + 3 * pat[3] + 2 * pat[2] + pat[1];
    ld ans = (ld)ans1 / total;
    REP(i, N - 1)
    {
        ld nans = 0;
        REP(j, 6)
        {
            nans += (ld)1 / (ld)6 * max((ld)j + 1, ans);
        }
        ans = nans;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    cout << ans << endl;

    return 0;
}