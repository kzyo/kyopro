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
    ll W, N;
    cin >> W >> N;

    vector<ll> h(W + 1, 0);

    ll L, R;
    REP(i, N)
    {
        cin >> L >> R;
        ll maxh = 0;
        for (ll ii = L; ii <= R; ii++)
        {
            maxh = max(maxh, h[ii]);
        }
        maxh++;
        cout << maxh << endl;
        for (ll ii = L; ii <= R; ii++)
        {
            h[ii] = maxh;
        }
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}