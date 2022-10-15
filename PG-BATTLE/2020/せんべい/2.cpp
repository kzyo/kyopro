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

    ll x = 10;
    ll keta = -1;

    REP(i, N)
    {
        ll tmp = x;
        while (tmp / 10 != 0)
            tmp /= 10;
        if (tmp < 5)
            keta++;

        ll mod = x % 10;
        if (mod != 0 && mod != 5)
        {
            x *= 10;
        }

        x /= 5;
    }

    cout << "0.";
    REP(i, keta)
    {
        cout << '0';
    }
    cout << x << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}