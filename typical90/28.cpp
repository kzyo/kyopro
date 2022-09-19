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

    vector dim(1002, vector<ll>(1002, 0));
    REP(i, N)
    {
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        dim[lx][ly]++;
        dim[rx][ry]++;
        dim[lx][ry]--;
        dim[rx][ly]--;
    }

    for (ll i = 1; i < 1001; i++)
    {
        for (ll j = 0; j < 1001; j++)
        {
            dim[i][j] += dim[i - 1][j];
        }
    }

    for (ll i = 1; i < 1001; i++)
    {
        for (ll j = 0; j < 1001; j++)
        {
            dim[j][i] += dim[j][i - 1];
        }
    }

    vector<ll> ans(N + 1, 0);
    for (ll i = 0; i < 1001; i++)
    {
        for (ll j = 0; j < 1001; j++)
        {
            ans[dim[j][i]]++;
        }
    }

    REP(i, N)
    {
        cout << ans[i + 1] << endl;
    }
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}