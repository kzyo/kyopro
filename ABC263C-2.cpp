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
    int N, M;
    cin >> N >> M;

    ll a[N];
    ll max = pow(M, N);
    REP(i, max)
    {
        ll t = i;
        bool ok = true;
        RREP(j, N)
        {
            int tt = t % M;
            t /= M;
            a[j] = tt + 1;
            if (j < N - 1)
            {
                if (a[j] >= a[j + 1])
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
        {
            REP(j, N)
            {
                cout << a[j];
                if (j == N - 1)
                    break;
                cout << " ";
            }
            cout << endl;
        }
    }
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}