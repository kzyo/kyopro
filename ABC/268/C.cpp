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

    vector<ll> v(N);
    REP(i, N)
    {
        cin >> v[i];
        v[i] -= i;
        if (v[i] > 0)
            v[i] -= N;
    }

    sort(v.begin(), v.end());

    ll ans = 0;

    ll tans = 0;
    ll si = 0;
    ll cv = v[0];

    REP(i, N)
    {
        tans++;

        if (v[i] > cv + 2)
        {
            while (v[si] == cv)
            {
                si++;
                tans--;
            }
            cv = v[si];
        }

        ans = max(ans, tans);
    }

    // 2
    REP(i, N)
    {
        v[i] += 1;
        if (v[i] > 0)
            v[i] -= N;
    }

    sort(v.begin(), v.end());

    tans = 0;
    si = 0;
    cv = v[0];

    REP(i, N)
    {
        tans++;

        if (v[i] > cv + 2)
        {
            while (v[si] == cv)
            {
                si++;
                tans--;
            }
            cv = v[si];
        }

        ans = max(ans, tans);
    }

    //3
    REP(i, N)
    {
        v[i] += 1;
        if (v[i] > 0)
            v[i] -= N;
    }

    sort(v.begin(), v.end());

    tans = 0;
    si = 0;
    cv = v[0];

    REP(i, N)
    {
        tans++;

        if (v[i] > cv + 2)
        {
            while (v[si] == cv)
            {
                si++;
                tans--;
            }
            cv = v[si];
        }

        ans = max(ans, tans);
    }

    cout << ans << endl;
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}