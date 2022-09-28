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

    vector<ll> A(N);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, less<pair<ll, ll>>> pq; // 降順

    REP(i, N)
    {
        ll b;
        cin >> A[i] >> b;
        pq.push(make_pair((ll)b, (ll)i));
    }

    ll ans = 0;
    REP(i, K)
    {
        auto p = pq.top();
        pq.pop();

        ans += p.first;

        if (p.second != -1)
        {
            pq.push(make_pair((ll)A[p.second] - p.first, (ll)-1));
        }
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}