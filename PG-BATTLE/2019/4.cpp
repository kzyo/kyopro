#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

struct cost
{
    ll c;
    ll d;
};

ll N, M, T, K;

/* ダイクストラ法 ノードは1~N(0始まりではない)の想定
    戻り 各ノードへのコスト
    引数 
    G: 辺とコスト G[from] = vector<pair<to, cost>>
    s: 開始ノード
*/
vector<ll> dijkstra(vector<vector<pair<ll, cost>>> G, ll startNode)
{
    ll N = G.size();
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(pair<ll, ll>{0, startNode});

    vector<ll> dist(N, __LONG_LONG_MAX__);
    dist[startNode] = 0;

    while (!pq.empty())
    {
        pair<ll, ll> costNode = pq.top();
        pq.pop();
        if (costNode.first > dist[costNode.second])
            continue;

        for (auto toCost : G[costNode.second])
        {
            ll to = toCost.first;
            ll cost = toCost.second.c;
            if (toCost.second.d <= K)
            {
                // ok
            }
            else
            {
                ll fromTime = T + K - toCost.second.d;
                ll toTime = T - K + toCost.second.d;
                if ((dist[costNode.second] <= fromTime && (dist[costNode.second] + cost) > fromTime) ||
                    (dist[costNode.second] < toTime && (dist[costNode.second] + cost) >= toTime) ||
                    (dist[costNode.second] >= fromTime && (dist[costNode.second] + cost) <= toTime))
                {
                    cost += toTime - dist[costNode.second];
                }
            }

            if (dist[to] > dist[costNode.second] + cost)
            {
                dist[to] = dist[costNode.second] + cost;
                pq.push(pair<ll, ll>{dist[to], to});
            }
        }
    }

    return dist;
}

int main()
{
    cin >> N >> M >> T >> K;
    vector G(N + 1, vector<pair<ll, cost>>());
    for (ll i = 1; i <= M; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cost cos = {c : c, d : d};
        G[a].push_back({b, cos});
        G[b].push_back({a, cos});
    }

    auto ans = dijkstra(G, 1);
    if (ans[N] == LLONG_MAX)
    {
        ans[N] = -1;
    }
    cout << ans[N] << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}