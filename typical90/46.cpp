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

    vector<int> A(46, 0);
    REP(i, N)
    {
        int t;
        cin >> t;
        A[t % 46] += 1;
    }

    vector<int> B(46, 0);
    REP(i, N)
    {
        int t;
        cin >> t;
        B[t % 46] += 1;
    }

    vector<int> C(46, 0);
    REP(i, N)
    {
        int t;
        cin >> t;
        C[t % 46] += 1;
    }

    ll ans = 0;
    REP(i, 46)
    {
        REP(j, 46)
        {
            ans += (ll)A[i] * (ll)B[j] * C[(46 - ((i + j) % 46)) % 46];
        }
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}