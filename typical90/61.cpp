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
    ll q;
    cin >> q;

    deque<ll> que;
    REP(i, q)
    {
        ll t, x;
        cin >> t >> x;

        if (t == 1)
        {
            que.push_front(x);
        }
        if (t == 2)
        {
            que.push_back(x);
        }
        if (t == 3)
        {
            cout << que[x - 1] << endl;
        }
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}