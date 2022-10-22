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
    ll P;
    cin >> P;

    ld ans = 0;
    ans += (P * P * P * P) / (ld)1000000;
    ans += 4 * P * P * P * P * (100 - P) / (ld)100000000;
    ans += 10 * P * P * P * P * (100 - P) * (100 - P) / (ld)10000000000;
    ans += 20 * P * P * P * P * (100 - P) * (100 - P) * (100 - P) / (ld)1000000000000;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    cout << ans << endl;
    return 0;
}