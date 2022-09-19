#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

vector g(100000 + 1, vector<ll>());
vector r(100000 + 1, vector<ll>());
vector<ll> n(100000);
vector<bool> visited;
ll cnt = 0;
void bfs(ll s)
{
    queue<ll> q;
    q.push(s);
    visited[s] = true;
    cnt++;

    while (!q.empty())
    {
        ll now = q.back();
        q.pop();

        for (ll nn : r[now])
        {
            if (!visited[nn])
            {
                visited[nn] = true;
                cnt++;
                q.push(nn);
            }
        }
    }
}

void dfs2(ll node)
{
    visited[node] = true;
    cnt++;
    for (ll nn : r[node])
    {
        if (!visited[nn])
            dfs2(nn);
    }
}

ll now = 0;
void dfs(ll node)
{
    visited[node] = true;
    for (ll nn : g[node])
    {
        if (visited[nn])
            continue;
        dfs(nn);
    }

    n[now++] = node;
}

int main()
{
    ll N, M;
    cin >> N >> M;

    REP(i, M)
    {
        ll a, b;
        cin >> a >> b;

        g[a].push_back(b);
        r[b].push_back(a);
    }

    visited = vector<bool>(N + 1, false);
    ll now = 0;
    for (ll node = 1; node <= N; node++)
    {
        if (!visited[node])
        {
            dfs(node);
        }
    }

    visited = vector<bool>(N + 1, false);
    reverse(n.begin(), n.begin() + N);
    vector<ll> count;
    for (ll node : n)
    {
        if (!visited[node])
        {
            cnt = 0;
            bfs(node);
            count.push_back(cnt);
        }
    }

    ll ans = 0;
    for (ll c : count)
    {
        ans += c * (c - 1LL) / 2LL;
    }
    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}
