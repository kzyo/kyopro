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
    ll N, K;
    cin >> N >> K;
    N++;

    map<ll, ll> m;
    m[0] = 1;
    m[1] = 1;

    REP(i, N)
    {
        if (m[i] > 0)
            continue;
        m[i]++;
        for (ll j = i * 2; j < N; j += i)
        {
            m[j]++;
        }
    }

    ll ans = 0;
    m[0] = 0;
    m[1] = 0;
    REP(i, N)
    {
        if (m[i] >= K)
            ans++;
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}