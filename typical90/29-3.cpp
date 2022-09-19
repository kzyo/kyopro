#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

ll id()
{
    return LLONG_MAX;
}
ll e()
{
    return -1;
}

ll op(ll a, ll b) { return max(a, b); }
ll mapping(ll f, ll s) { return f == id() ? s : f; }
ll composition(ll org_f, ll child_f) { return org_f == id() ? child_f : org_f; }

int main()
{
    ll W, N;
    cin >> W >> N;

    vector<ll> v(W + 2, 0);
    lazy_segtree<ll, op, e, ll, mapping, composition, id> lseg(v);
    REP(i, N)
    {
        ll L, R;
        cin >> L >> R;
        ll ans = lseg.prod(L, R + 1) + 1;
        cout << ans << endl;
        lseg.apply(L, R + 1, ans);
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}