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
    ll T;
    cin >> T;

    // vector<ll> v;
    // v.push_back(0);
    // ll j = 1;
    // ll now = 0;
    // while (now < 500000000000000000)
    // {
    //     now += j;
    //     v.push_back(now);
    //     j++;
    // }

    REP(i, T)
    {
        ll N, M;
        cin >> N >> M;
        ll mi = max((ll)1, N - M);

        ll l = -1, r = N;
        while (r - l > 1)
        {
            ll m = l + (r - l) / 2;
            ll m1 = m * (m - 1) / 2;
            ll m2 = m * (m + 1) / 2;
            if (M <= m1)
            {
                r = m;
            }
            else if (M > m2)
            {
                l = m;
            }
            else
            {
                r = m;
                break;
            }
        }

        // auto pos = lower_bound(v.begin(), v.end(), M);
        ll ma = N - r;
        // if (ma < 1)
        //     ma = 1;

        cout << mi << ' ' << ma << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}