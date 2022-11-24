#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint1000000007;

int main()
{
    int N;
    cin >> N;

    mint ans = 1;

    REP(i, N)
    {
        int p = 0;
        REP(j, 6)
        {
            int t;
            cin >> t;
            p += t;
        }
        ans *= p;
    }

    cout << ans.val() << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}