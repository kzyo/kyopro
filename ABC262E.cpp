#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define RREP(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

ll N, M, K;
vector<ll> G[200010];

int main()
{
    cin >> N >> M >> K;
    REP(i, M) {
        ll u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}