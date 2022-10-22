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
    vector<ll> A(N);
    REP(i, N)
    {
        cin >> A[i];
    }

    for (ll i = N - 1; i >= 0; i--)
    {
        if (A[i] == 1)
        {
            ll now = 1;
            while (true)
            {
                if (A[i] != now)
                    break;
                A.erase(A.begin() + i);
                now++;
            }
        }
    }

    ll ans = 0;
    REP(i, A.size())
    ans += A[i];

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}