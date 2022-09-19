#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

// 弧度法から度数法への変換
ld radToDeg(ld rad)
{
    return 180 * rad / M_PI;
}

// 点(baseX, baseY)を原点とした場合の原点と点(x, y)を繋いだ直線のX軸からの角度
// 戻り: [0 ~ 2π]
ld radFromXAxis(ll x, ll y, ll baseX, ll baseY)
{
    ll xx = x - baseX;
    ll yy = y - baseY;

    ld ret = atan2l(yy, xx);
    if (ret < 0)
        ret += M_PI * 2;

    return ret;
}

bool check(ll ax, ll ay, ll bx, ll by, ll cx, ll cy)
{
    ld r1 = radFromXAxis(ax, ay, bx, by);
    ld r2 = radFromXAxis(cx, cy, bx, by);

    ld r = r1 - r2;
    if (r < 0)
        r += 2 * M_PI;
    ld d = radToDeg(r);
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