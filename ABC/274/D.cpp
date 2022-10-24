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
    ll N, x, y;
    cin >> N >> x >> y;

    ll a1;
    cin >> a1;
    x -= a1;
    x = abs(x);
    y = abs(y);

    map<ll, ll> xmap, ymap;
    ll tx = 0, ty = 0;
    REP(i, N - 1)
    {
        ll n;
        cin >> n;
        if (i % 2 == 0)
        {
            ymap[n]++;
            ty += n;
        }
        else
        {
            xmap[n]++;
            tx += n;
        }
    }

    ll dx = tx - x;
    ll dy = ty - y;
    if (dx < 0 || dy < 0 || dx % 2 == 1 || dy % 2 == 1)
    {
        cout << "No" << endl;
        return 0;
    }

    dx /= 2;
    dy /= 2;
    map<ll, ll> xmapu, ymapu;

    ll nowx = 0, nowy = 0;
    ll predx = LLONG_MAX, prepredx = LLONG_MIN;
    while (dx != 0)
    {
        for (int i = 1; i <= 10; i++)
        {
            if (nowx >= dx)
                break;
            while (xmapu[i] < xmap[i])
            {
                nowx += i;
                xmapu[i] += 1;
                if (nowx >= dx)
                {
                    break;
                }
            }
        }
        prepredx = predx;
        predx = dx;
        dx = nowx - dx;
        nowx = 0;
        if (prepredx == dx)
        {
            cout << "No" << endl;
            return 0;
        }
        xmap = xmapu;
        xmapu = map<ll, ll>();
    }

    ll predy = LLONG_MAX, prepredy = LLONG_MIN;
    while (dy != 0)
    {
        for (int i = 1; i <= 10; i++)
        {
            if (nowy >= dy)
                break;
            while (ymapu[i] < ymap[i])
            {
                nowy += i;
                ymapu[i] += 1;
                if (nowy >= dy)
                {
                    break;
                }
            }
        }
        prepredy = predy;
        predy = dy;
        dy = nowy - dy;
        nowy = 0;
        if (prepredy == dy)
        {
            cout << "No" << endl;
            return 0;
        }
        ymap = ymapu;
        ymapu = map<ll, ll>();
    }

    cout << "Yes" << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}