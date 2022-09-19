#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

ll ten9 = 1000000000;

int main()
{
    ll N;
    cin >> N;

    vector<ll> a(N);
    REP(i, N)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto uniqi = unique(a.begin(), a.end());
    a.erase(uniqi, a.end());

    REP(i, a.size() - 1)
    {
        a[i + 1] -= a[0];
    }
    a[0] = 0;

    if (a[1] == 1)
    {
        cout << 2 << endl;
        return 0;
    }

    if (a.size() == 2)
    {
        cout << 1 << endl;
        return 0;
    }

    ll g = gcd(a[1], a[2]);
    if (g == 1)
    {
        cout << 2 << endl;
        return 0;
    }

    ll ans = 1;
    for (ll i = 3; i < a.size(); i++)
    {
        ll gg = gcd(a[1], a[i]);
        if (gg != g)
        {
            g = gcd(g, gg);
            if (g > 1)
                continue;
            ans = 2;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}