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
    int N, L, R;
    cin >> N >> L >> R;

    int A[N];
    REP(i, N)
    cin >> A[i];

    ld tmp[N];
    ld max = -10000000000;
    int max_idx = -1;
    ld total = 0;
    for (int i = 1; i <= N; i++)
    {
        total += A[N - i];
        tmp[i - 1] = (ld)total / i;
        if (tmp[i - 1] >= max)
        {
            max = tmp[i - 1];
            max_idx = i;
        }
    }
    if (max > R)
    {
        REP(i, max_idx)
        {
            A[N - 1 - i] = R;
        }
    }

    //L
    max = -10000000000;
    max_idx = -1;
    total = 0;
    for (int i = 1; i <= N; i++)
    {
        total += A[i - 1];
        tmp[i - 1] = (ld)total / i;
        if (tmp[i - 1] >= max)
        {
            max = tmp[i - 1];
            max_idx = i;
        }
    }
    if (max > L)
    {
        REP(i, max_idx)
        {
            A[i] = L;
        }
    }

    // R
    max = -10000000000;
    max_idx = -1;
    total = 0;
    for (int i = 1; i <= N; i++)
    {
        total += A[N - i];
        tmp[i - 1] = (ld)total / i;
        if (tmp[i - 1] >= max)
        {
            max = tmp[i - 1];
            max_idx = i;
        }
    }
    if (max > R)
    {
        REP(i, max_idx)
        {
            A[N - 1 - i] = R;
        }
    }

    ll ans = 0;
    REP(i, N)
    ans += A[i];

    cout << ans << endl;
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}