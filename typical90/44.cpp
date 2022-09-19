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
    ll N, Q;
    cin >> N >> Q;

    deque<ll> que(N);
    REP(i, N)
    cin >> que[i];

    REP(i, Q)
    {
        ll t, x, y;
        cin >> t >> x >> y;

        ll back;
        switch ((int)t)
        {
        case 1:
            swap(que[x - 1], que[y - 1]);
            break;

        case 2:
            back = que[que.size() - 1];
            que.pop_back();
            que.push_front(back);
            break;

        case 3:
            cout << que[x - 1] << endl;
            break;

        default:
            break;
        }
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}