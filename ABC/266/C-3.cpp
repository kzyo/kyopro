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
    ll x1 = ax - bx;
    ll y1 = ay - by;
    ll x2 = cx - bx;
    ll y2 = cy - by;

    ll prod = x2 * y1 - x1 * y2;
    bool ok = true;
    if (prod < 0)
        ok = false;
    return ok;
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