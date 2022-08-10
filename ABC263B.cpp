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
    int N;
    cin >> N;

    int P[N];
    REP(i, N - 1)
    {
        cin >> P[i];
    }

    int ans = 0;
    int nxt = N - 2;
    while (true)
    {
        ans++;
        if (P[nxt] == 1)
            break;
        nxt = P[nxt] - 2;
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}