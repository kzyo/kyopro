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
    ll N, M;
    cin >> N >> M;

    ll Q;
    cin >> Q;
    REP(i, Q)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        mint ans = 0;
        ll n = (b - a + 1);
        ans += n
            ans += n * (n + 1) / 2 * M;

        ll n2 = d - c + 1;
        mint finalAns = ans * n2;
        finalAns +=
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}