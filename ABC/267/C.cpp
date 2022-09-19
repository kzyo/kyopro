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
    ll N, M;
    cin >> N >> M;

    vector<ll> a(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    vector<ll> cum(N - M + 1);
    ll c = 0;
    REP(i, M - 1)
    {
        c += a[i];
    }
    ll base = M - 1;
    REP(i, N - M + 1)
    {
        if (i > 0)
            c -= a[i - 1];
        c += a[base + i];
        cum[i] = c;
    }

    ll ans = 0;
    REP(i, M)
    {
        ans += (i + 1) * a[i];
    }

    ll cur = ans;
    REP(i, N - M)
    {

        cur -= cum[i];
        cur += a[M + i] * M;
        ans = max(ans, cur);
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}