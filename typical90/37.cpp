#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

ll op(ll a, ll b)
{
    return max(a, b);
}

ll e()
{
    return LLONG_MIN;
}

int main()
{
    ll W, N;
    cin >> W >> N;

    segtree<ll, op, e> preSeg(W + 1);
    preSeg.set(0, 0);

    REP(i, N)
    {
        ll l, r, v;
        cin >> l >> r >> v;

        segtree<ll, op, e> nxtSeg(W + 1);
        REP(j, W + 1)
        {
            ll lll = max((ll)0, j - r);
            ll rrr = j - l + 1;
            ll addV = LLONG_MIN;
            if (rrr > 0)
                addV = preSeg.prod(lll, rrr) + v;

            ll cur = preSeg.get(j);

            nxtSeg.set(j, max(cur, addV));
        }
        preSeg = nxtSeg;
    }

    ll ans = preSeg.get(W) < 0 ? -1 : preSeg.get(W);
    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}