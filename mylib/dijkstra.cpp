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