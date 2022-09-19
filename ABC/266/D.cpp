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
    vector<ll> pre(5, LLONG_MIN);
    pre[0] = 0;

    ll N;
    cin >> N;

    ll t, x, a;
    ll now = 1;
    REP(i, N)
    {
        cin >> t >> x >> a;
        for (; now <= t; now++)
        {
            vector<ll> cur(5);
            cur[0] = max(pre[0], pre[1]);
            cur[1] = max(pre[0], max(pre[1], pre[2]));
            cur[2] = max(pre[1], max(pre[2], pre[3]));
            cur[3] = max(pre[2], max(pre[3], pre[4]));
            cur[4] = max(pre[3], pre[4]);
            pre = cur;
        }
        pre[x] += a;
    }

    ll ans = max(pre[0], max(pre[1], max(pre[2], max(pre[3], pre[4]))));

    cout << ans << endl;

    cout
        << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}