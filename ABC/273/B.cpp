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
    ll X, K;
    cin >> X >> K;

    ll tmp = 10;
    REP(i, K)
    {
        ll mod = X % tmp;
        X -= mod;
        REP(j, i)
        {
            mod /= 10;
        }

        if (mod >= 5)
        {
            ll add = 10;
            REP(j, i)
            {
                add *= 10;
            }
            X += add;
        }

        tmp *= 10;
    }

    cout << X << endl;

    cout
        << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}