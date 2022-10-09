#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint1000000007;

ll ncr(ll n, ll r, int mod)
{
    ll factorial[n + 1];
    factorial[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        factorial[i] = i * factorial[i - 1] % mod;
    }

    ll fact_inv[n + 1];
    fact_inv[n] = pow_mod(factorial[n], mod - 2, mod);
    for (ll i = n; i >= 1; i--)
    {
        fact_inv[i - 1] = fact_inv[i] * i % mod;
    }

    return (factorial[n] * fact_inv[r]) % mod * fact_inv[n - r] % mod;
}

int main()
{
    ll N, L;
    cin >> N >> L;

    ll n = N, r = N, remain = N;
    mint ans = 0;

    while (true)
    {
        ans += ncr(n, r, 1000000007);

        if (remain < L)
            break;

        remain -= L;
        n = n - L + 1;
        r -= L;
    }

    cout << ans.val() << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}