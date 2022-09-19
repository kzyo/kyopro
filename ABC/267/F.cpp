#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

ll N;
struct node
{
    ll level;
    ll upNode;
    ll downNode;
};

vector<vector<ll>> G;
vector<node> nodes;
ll maxLevel = -1;
ll secondeLevel = -1;
vector<ll> maxPath;
vector<ll> secondPath;

void dfs(ll start, ll level, ll from)
{
    node n = nodes[start];
    n.level = level;
    n.upNode = from;
    n.downNode = -1;
    for (ll nextNode : G[start])
    {
        n.downNode = nextNode;
        dfs(nextNode, level + 1, start);
    }
    nodes[start] = n;

    if (level <= maxLevel && level > secondeLevel)
    {
        vector<ll> path;
        ll curNode = start;
        while (true)
        {
            path.push_back(curNode);
            if (nodes[curNode].upNode == -1)
            {
                break;
            }
            else
            {
                curNode = nodes[curNode].upNode;
            }
        }
        reverse(path.begin(), path.end());
        secondeLevel = level;
        secondPath = path;
    }

    if (level > maxLevel)
    {
        vector<ll> path;
        ll curNode = start;
        while (true)
        {
            path.push_back(curNode);
            if (nodes[curNode].upNode == -1)
            {
                break;
            }
            else
            {
                curNode = nodes[curNode].upNode;
            }
        }
        reverse(path.begin(), path.end());
        secondeLevel = maxLevel;
        secondPath = maxPath;
        maxLevel = level;
        maxPath = path;
    }
}

int main()
{
    cin >> N;

    G = vector(N + 1, vector<ll>());
    REP(i, N)
    {
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    nodes = vector<node>(N + 1);
    dfs(1, 1, -1);

    ll Q;
    cin >> Q;
    REP(i, Q)
    {
        ll u, k;
        cin >> u >> k;
        node n = nodes[u];
        ll ans = -1;
        if (n.level - 1 <= k)
        {
            REP(i, k)
            {
                ans = n.upNode;
                n = nodes[n.upNode];
            }
        }
        else
        {
            ll ttt = count(maxPath.begin(), maxPath.end(), u);
            if (ttt == 0)
            {
                if (n.level - 1 + maxLevel - 1 <= k)
                {
                    k -= n.level - 1;
                    ans = maxPath[k];
                }
            }
            else
            {
                if (n.level - 1 + secondeLevel - 1 <= k)
                {
                    k -= n.level - 1;
                    ans = secondPath[k];
                }
            }
        }
        cout << ans << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}