#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define RREP(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

vector<int> G[110];
int N, M;

int main()
{
    cin >> N >> M;
    REP(i, M) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll cnt = 0;
    REP(ii, N) {
        ll i = ii + 1;
        for(int j: G[i]) {
            if (j <= i) continue;
            for(int k: G[j]) {
                if (k <= j) continue;
                for(int l: G[k]) {
                    if (l == i) cnt++;
                }
            }
        }
    }

    cout << cnt << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}