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
    ll N, K;
    cin >> N >> K;

    ll cycle[100000];
    vector visited(100000, false);
    cycle[0] = N;
    visited[N] = true;

    ll idx = 1;
    while (true)
    {
        ll n = N;
        ll d = 0;
        REP(i, 5)
        {
            d += n % 10;
            n /= 10;
        }

        N += d;
        N %= 100000;
        if (visited[N])
            break;

        visited[N] = true;
        cycle[idx] = N;

        idx++;
    }

    ll si = 0;
    while (true)
    {
        if (cycle[si] == N)
            break;
        si++;
    }

    ll loop_dist = idx - si;

    if (K <= si)
    {
        cout << cycle[K] << endl;
    }
    else
    {
        K -= si;
        cout << cycle[(K % loop_dist) + si] << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}