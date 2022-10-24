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
    ll A, B;
    cin >> A >> B;
    B *= 1000;
    ld ans = B / (ld)A;
    auto ans2 = round(ans) / 1000;

    cout
        << fixed << setprecision(3); // 小数点以下20桁まで表示
    cout << ans2 << endl;
    return 0;
}