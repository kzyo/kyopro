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
    ll a, b, c;
    cin >> a >> b >> c;

    ll h = gcd(a, b);
    h = gcd(h, c);

    ll ans = a / h - 1;
    ans += b / h - 1;
    ans += c / h - 1;

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}