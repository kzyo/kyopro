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
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示

    ll T, L, X, Y;
    cin >> T >> L >> X >> Y;

    ll Q;
    cin >> Q;
    REP(i, Q)
    {
        ll t;
        cin >> t;
        ld theta = (ld)2 * M_PI / T * t;
        ld y = sinl(theta) * -L / 2;
        ld z = (ld)L / 2 * ((ld)1 - cosl(theta));

        ld bottom = hypotl(X, Y - y);
        ld hyp = sqrtl(X * X + (Y - y) * (Y - y) + z * z);
        ld ansrad = acosl(bottom / hyp);
        ld ans = ansrad / (2 * M_PI) * 360;
        cout << ans << endl;
    }

    return 0;
}