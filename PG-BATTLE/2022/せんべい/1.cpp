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
    ll N, Q;
    cin >> N >> Q;

    vector<bool> res(N, false);

    REP(i, Q)
    {
        ll L, R;
        cin >> L >> R;
        for (int j = L - 1; j < R; j++)
        {
            res[j] = !res[j];
        }
    }

    ll ans = 0;
    REP(i, N)
    {
        if (res[i])
            ans++;
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}