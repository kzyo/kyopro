#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint1000000007;

unsigned int solve(ll N, ll K)
{
    if (N == 1)
        return K;
    if (N == 2)
        return K * (K - 1);

    mint ans = K * (K - 1);

    ans *= pow_mod(K - 2, N - 2, 1000000007);

    if (ans.val() < 0)
        ans = 0;

    return ans.val();
}

int main()
{
    ll N, K;
    cin >> N >> K;

    cout << solve(N, K) << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}