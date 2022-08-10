#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

bool visited[100010];
bool visited2[100010];

pair<int, int> get_dist(vector<int> *road, int start, bool* visited) {
    int max_dist = 0;
    int max_node = start;
    visited[start] = true;
    for(int n: road[start]) {
        if (visited[n]) continue;
        visited[n] = true;

        pair<int, int> nxt = get_dist(road, n, visited);
        int dist = nxt.first + 1;
        if (dist > max_dist) {
            max_dist = dist;
            max_node = nxt.second;
        }
    }
    return {max_dist, max_node};
}

int main()
{
    ll N;
    cin >> N;

    vector<int> road[N+1];

    REP(i, N) {
        int a,b;
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }


    pair<int, int> first = get_dist(road, 1, visited);
    pair<int, int> second = get_dist(road, first.second, visited2);
    

    cout << second.first + 1 << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}