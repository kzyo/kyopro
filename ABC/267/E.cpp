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
    ll N, M;
    cin >> N >> M;

    vector<ll> v(N + 1);
    REP(i, N)
    cin >> v[i + 1];

    vector G(N + 1, vector<ll>());
    REP(i, M)
    {
        ll u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<ll> costs(N + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; //cost, node
    for (ll i = 1; i <= N; i++)
    {
        ll cost = 0;
        for (ll node : G[i])
        {
            cost += v[node];
        }
        pq.push({cost, i});
        costs[i] = cost;
    }

    vector<bool> deleted(N + 1, false);
    ll maxCost = LLONG_MIN;
    while (!pq.empty())
    {
        auto item = pq.top();
        ll cost = item.first;
        ll node = item.second;
        pq.pop();
        if (deleted[node])
            continue;
        deleted[node] = true;
        maxCost = max(maxCost, cost);

        for (ll n : G[node])
        {
            costs[n] -= v[node];
            pq.push({costs[n], n});
        }
    }

    cout << maxCost << endl;
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}