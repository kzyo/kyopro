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

    vector<vector<pair<ll, ll>>> G(N + 1); // G[from] = vector<pair<to, cost>>
    REP(i, M)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(pair<ll, ll>{b, c});
        G[b].push_back(pair<ll, ll>{a, c});
    }

    // auto comp = [](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; }; // pair<node, cost>
    //priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(comp)> pq{comp};
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(pair<ll, ll>{0, 1});

    vector<ll> dist(N + 1, __LONG_LONG_MAX__);
    dist[1] = 0;

    while (!pq.empty())
    {
        pair<ll, ll> costNode = pq.top();
        pq.pop();
        if (costNode.first > dist[costNode.second])
            continue;

        for (auto toCost : G[costNode.second])
        {
            ll to = toCost.first;
            ll cost = toCost.second;

            if (dist[to] > dist[costNode.second] + cost)
            {
                dist[to] = dist[costNode.second] + cost;
                pq.push(pair<ll, ll>{dist[to], to});
            }
        }
    }

    vector<ll> dist2(N + 1, __LONG_LONG_MAX__);
    dist2[N] = 0;
    pq.push(pair<ll, ll>{0, N});

    while (!pq.empty())
    {
        pair<ll, ll> costNode = pq.top();
        pq.pop();
        if (costNode.first > dist2[costNode.second])
            continue;

        for (auto toCost : G[costNode.second])
        {
            ll to = toCost.first;
            ll cost = toCost.second;

            if (dist2[to] > dist2[costNode.second] + cost)
            {
                dist2[to] = dist2[costNode.second] + cost;
                pq.push(pair<ll, ll>{dist2[to], to});
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << dist[i] + dist2[i] << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}