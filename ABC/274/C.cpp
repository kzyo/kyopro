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
    ll N;
    cin >> N;
    vector<ll> v(1 + 2 * N, 0);

    REP(i, N)
    {
        ll n;
        cin >> n;

        v[2 * (i + 1) - 1] = v[n - 1] + 1;
        v[2 * (i + 1)] = v[n - 1] + 1;
    }

    for (auto n : v)
    {
        cout << n << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}