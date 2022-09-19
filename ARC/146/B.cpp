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
    ll N, M, K;
    cin >> N >> M >> K;

    vector<ll> a(N);
    REP(i, N)
    cin >> a[i];

    ll ans = 0;
    RREP(i, 31)
    {
        vector<ll> b(N, 0);
        ll bit = 1 << i;
        ll bit_inv = bit - 1;
        vector<ll> matched_num;
        REP(j, a.size())
        {
            if ((a[j] & bit) > 0)
            {
                matched_num.push_back(a[j]);
            }
            else
            {
                b[j] = a[j] & bit_inv;
            }
        }
        sort(b.begin(), b.end(), greater<ll>());

        ll suff_num = K - matched_num.size();
        if (suff_num > 0)
        {
            ll n = 0;
            REP(j, suff_num)
            {
                n += b[j];
            }
            ll suff_num_num = bit * suff_num - n;
            if (suff_num_num > M)
                continue;
            M -= suff_num_num;
            REP(j, suff_num)
            matched_num.push_back(bit);
        }

        ans += bit;
        a = matched_num;
    }

    ans += M / K;

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}