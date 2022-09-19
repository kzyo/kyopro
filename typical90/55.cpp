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
    ll n, p, q;
    cin >> n >> p >> q;

    vector<ll> a(n);
    REP(i, n)
    cin >> a[i];

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < i; j++)
        {
            for (ll k = 0; k < j; k++)
            {
                for (ll h = 0; h < k; h++)
                {
                    for (ll l = 0; l < h; l++)
                    {
                        if (a[i] * a[j] % p * a[k] % p * a[h] % p * a[l] % p == q)
                            ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}