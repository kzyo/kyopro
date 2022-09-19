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
vector<vector<ll>> g;
int main()
{
    cin >> N;
    g = vector(N + 1, vector<ll>());

    REP(i, N)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

cout << fixed << setprecision(20); // 小数点以下20桁まで表示
return 0;
}