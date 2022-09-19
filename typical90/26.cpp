#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

vector<vector<ll>> G;
vector ans(2, vector<ll>());
vector<bool> visited;

void dfs(ll pos, ll color)
{
    visited[pos] = true;
    ans[color].push_back(pos);

    for (ll p : G[pos])
    {
        if (visited[p])
            continue;

        dfs(p, (color + 1) % 2);
    }
}

int main()
{
    ll N;
    cin >> N;

    G = vector(N + 1, vector<ll>());

    REP(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    visited = vector<bool>(N + 1, false);
    dfs(1, 0);

    ll idx = 0;
    if (ans[idx].size() < N / 2)
        idx++;

    cout << ans[idx][0];
    REP(i, N / 2 - 1)
    {
        cout << ' ';
        cout << ans[idx][i + 1];
    }
    cout << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}