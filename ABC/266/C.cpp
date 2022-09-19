#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

bool check(ll ax, ll ay, ll bx, ll by, ll cx, ll cy)
{
    ax -= bx;
    ay -= by;
    cx -= bx;
    cy -= by;
    ld r1 = atan2l(ax, ay);
    ld r2 = atan2l(cx, cy);
    if (r1 < 0)
        r1 += M_PI * 2;
    if (r2 < 0)
        r2 += M_PI * 2;

    ld r = r2 - r1;
    if (r < 0)
        r += 2 * M_PI;
    ld d = 180 * r / M_PI;
    if (d < 180)
        return true;
    return false;
}

int main()
{
    ll ax, ay, bx, by, cx, cy, dx, dy;

    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    cin >> dx >> dy;

    bool ok = true;
    ok = ok && check(ax, ay, bx, by, cx, cy);
    ok = ok && check(bx, by, cx, cy, dx, dy);
    ok = ok && check(cx, cy, dx, dy, ax, ay);
    ok = ok && check(dx, dy, ax, ay, bx, by);

    if (ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}