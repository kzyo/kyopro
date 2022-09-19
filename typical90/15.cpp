#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<mint> ans(N);

    ans[0] = N;
    for (ll i = 1; i < N; i++)
    {
        ans[i] = ans[i - 1] + i;
    }
    reverse(ans.begin(), ans.end());

    REP(i, N)
    {
        cout << ans[i].val() << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}