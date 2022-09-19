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
    ll N;
    cin >> N;

    vector<ll> v(N);
    REP(i, N)
    {
        cin >> v[i];
    }

    vector<ll> c(N, 0);
    REP(i, N)
    {
        for (ll j = -1; j <= 1; j++)
        {
            c[(v[i] - i + j + N) % N]++;
        }
    }
    ll ans = 0;
    REP(i, N)
    ans = max(ans, c[i]);

    cout << ans << endl;
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}