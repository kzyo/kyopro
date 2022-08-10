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

    vector acc(2, vector<ll>(N + 1, 0));
    REP(i, N)
    {
        acc[0][i + 1] = acc[0][i];
        acc[1][i + 1] = acc[1][i];

        ll c, p;
        cin >> c >> p;
        acc[--c][i + 1] += p;
    }

    ll Q;
    cin >> Q;
    REP(i, Q)
    {
        ll l, r;
        cin >> l >> r;
        cout << acc[0][r] - acc[0][l - 1] << " " << acc[1][r] - acc[1][l - 1] << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}