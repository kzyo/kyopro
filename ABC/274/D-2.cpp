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

    vector<ll> xa, ya;
    REP(i, N - 1)
    {
        ll n;
        cin >> n;
        if (i % 2 == 0)
        {
            ya.push_back(n);
        }
        else
        {
            xa.push_back(n);
        }
    }

    const ll MAX = 10000;
    vector<bool> okx(2 * MAX + 1), oky(2 * MAX + 1);

    okx[MAX + a1] = true;
    for (ll n : xa)
    {
        vector<bool> nokx(2 * MAX + 1);
        REP(i, 2 * MAX + 1)
        {
            if (okx[i])
            {
                if (i + n <= 2 * MAX)
                    nokx[i + n] = true;
                if (i - n >= 0)
                    nokx[i - n] = true;
            }
        }
        okx = nokx;
    }

    oky[MAX] = true;
    for (ll n : ya)
    {
        vector<bool> noky(2 * MAX + 1);

        REP(i, 2 * MAX + 1)
        {
            if (oky[i])
            {
                if (i + n <= 2 * MAX)
                    noky[i + n] = true;
                if (i - n >= 0)
                    noky[i - n] = true;
            }
        }
        oky = noky;
    }

    if (oky[MAX + y] && okx[MAX + x])
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