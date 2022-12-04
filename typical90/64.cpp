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

    ll a[N];
    REP(i, N)
    cin >> a[i];

    ll d[N];
    REP(i, N - 1)
    d[i + 1] = a[i + 1] - a[i];

    ll ans = 0;
    REP(i, N - 1)
    ans += abs(d[i + 1]);

    REP(i, Q)
    {
        ll l, r, v;
        cin >> l >> r >> v;
        if (l - 1 > 0)
        {
            ll pre = abs(d[l - 1]);
            d[l - 1] += v;
            ll now = abs(d[l - 1]);
            ans += now - pre;
        }
        if (r < N)
        {
            ll pre = abs(d[r]);
            d[r] -= v;
            ll now = abs(d[r]);
            ans += now - pre;
        }

        cout << ans << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}