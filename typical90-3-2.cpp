#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

const ll MAX_N = 100010;
ll N;
vector<int> G[MAX_N];

typedef struct  {
    int dist;
    int node;
} dist_node;

dist_node get_max_dist_node(int start){
    int dists[N+1];
    REP(i, N+1) {
        dists[i] = MAX_N;
    }

    dists[start] = 0;

    queue<int> q;
    q.push(start);

    int max_dist = 0;
    int max_node = start;

    while(q.size() > 0) {
        int now = q.front(); q.pop();
        for(int nxt: G[now]) {
            if (dists[nxt] != MAX_N) continue;
            dists[nxt] = dists[now] + 1;
            q.push(nxt);

            if (dists[nxt] > max_dist) {
                max_dist = dists[nxt];
                max_node = nxt;
            }
        }
    }

    return dist_node{max_dist, max_node};
}

int main()
{
    cin >> N;
    REP(i, N){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dist_node first = get_max_dist_node(1);
    dist_node last = get_max_dist_node(first.node);
    
    cout << last.dist + 1 << endl;
    
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}