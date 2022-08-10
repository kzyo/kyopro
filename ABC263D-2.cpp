#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double
#define LL_MAX ~((ll)1 << 63)

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

int main()
{
    ll N, L, R;
    cin >> N >> L >> R;

    vector<ll> A(N);
    REP(i, N)
    cin >> A[i];

    ll f[N + 1];
    f[0] = 0;
    for (int i = 1; i < N + 1; i++)
    {
        f[i] = min(f[i - 1] + A[i - 1], L * i);
    }

    ll g[N + 1];
    g[0] = 0;
    reverse(A.begin(), A.end());
    for (int i = 1; i < N + 1; i++)
    {
        g[i] = min(g[i - 1] + A[i - 1], R * i);
    }

    ll ans = LL_MAX;
    REP(i, N + 1)
    {
        ans = min(ans, (ll)f[i] + g[N - i]);
    }

    cout << ans << endl;
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}