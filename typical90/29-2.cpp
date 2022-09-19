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
    ll W, N;
    cin >> W >> N;

    vector h(N + 1, vector<pair<ll, ll>>());
    h[0].push_back(pair<ll, ll>{0, W});
    ll maxh = 0;

    ll L, R;
    REP(i, N)
    {
        cin >> L >> R;
        bool matched = false;
        for (ll nowh = maxh; nowh >= 0; nowh--)
        {
            for (auto p : h[nowh])
            {
                if (L <= p.second && p.first <= R)
                {
                    matched = true;
                    h[nowh + 1].push_back(pair<ll, ll>{L, R});
                    break;
                }
            }
            if (matched)
            {
                nowh++;
                cout << nowh << endl;
                maxh = max(maxh, nowh);
                break;
            }
        }
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}