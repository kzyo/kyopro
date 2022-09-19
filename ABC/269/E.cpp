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

    ll w = N;
    ll pos = 1;
    REP(jj, 10)
    {
        ll remain = w % 2;
        w /= 2;
        if (w < 1)
            w = 1;
        // cout << printf("? 1 %d %d %d", N, pos, (pos + w - 1)) << endl;
        cout << "? 1 " << N << " " << pos << " " << (pos + w - 1) << endl;
        ll ret;
        cin >> ret;
        if (ret == -1)
            break;

        if (ret == 0)
        {
            break;
        }

        if (ret >= w)
        {
            pos += w;
            w += remain;
        }
    }

    w = N;
    ll jpos = pos;
    pos = 1;
    REP(ii, 10)
    {
        ll remain = w % 2;
        w /= 2;
        if (w < 1)
            w = 1;
        // cout << printf("? 1 %d %d %d", N, pos, (pos + w - 1)) << endl;
        cout << "? " << pos << " " << (pos + w - 1) << " 1 " << N << endl;
        ll ret;
        cin >> ret;
        if (ret == -1)
            break;

        if (ret == 0)
        {
            break;
        }

        if (ret >= w)
        {
            pos += w;
            w += remain;
        }
    }

    cout << "! " << pos << " " << jpos << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}