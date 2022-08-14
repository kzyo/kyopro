#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

/* ダイクストラ法 ノードは1~N(0始まりではない)の想定
    戻り 各ノードへのコスト
    引数 
    G: 辺とコスト G[from] = vector<pair<to, cost>>
    s: 開始ノード
*/
vector<ll> dijkstra(vector<vector<pair<ll, ll>>> G, ll startNode)
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
            ll cost = toCost.second;

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

    vector<ll> dist = dijkstra(G, 1);
    vector<ll> dist2 = dijkstra(G, N);

    for (int i = 1; i <= N; i++)
    {
        cout << dist[i] + dist2[i] << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}