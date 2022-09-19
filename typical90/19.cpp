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
    vector<ll> a(2 * N);
    vector<ll> b(2 * N - 1);
    cin >> a[0];
    REP(i, 2 * N - 1)
    {
        cin >> a[i + 1];
        b[i] = abs(a[i + 1] - a[i]);
    }

    ll ans = 0;
    REP(i, N - 1)
    {
        ll min = LONG_MAX;
        ll min_idx = -1;
        REP(j, 2 * N - 1 - 2 * i)
        {
            if (b[j] < min)
            {
                min_idx = j;
                min = b[j];
            }
        }

        ans += min;
        if (min_idx == 0 || min_idx + 1 == 2 * N - 1 - 2 * i)
        {
        }
        else
        {
            b[min_idx - 1] = abs(a[min_idx - 1] - a[min_idx + 2]);
        }

        a.erase(a.begin() + min_idx);
        a.erase(a.begin() + min_idx);
        b.erase(b.begin() + min_idx);
        if (min_idx == b.size())
        {
            b.erase(b.begin() + min_idx - 1);
        }
        else
        {
            b.erase(b.begin() + min_idx);
        }
    }
    ans += b[0];

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}