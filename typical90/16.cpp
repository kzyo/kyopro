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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll ans = 9999999;
    REP(i, 10000)
    REP(j, 10000)
    {
        ll r = n - (a * i + b * j);
        if (r < 0)
            continue;
        if (r % c == 0)
        {
            ans = min(ans, i + j + (r / c));
        }
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}