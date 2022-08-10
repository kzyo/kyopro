#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

int N, M;

void print(vector<int> num)
{
    REP(i, num.size())
    {
        cout << num[i];
        if (i < num.size() - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
}

void dfs(vector<int> n)
{
    if (n.size() == N)
    {
        print(n);
        return;
    }

    int start = 1;
    if (n.size() > 0)
        start = n.back() + 1;

    for (int num = start; num <= M; num++)
    {
        vector<int> new_n(n.size());
        copy(n.begin(), n.end(), new_n.begin());
        new_n.push_back(num);
        dfs(new_n);
    }
}

int main()
{
    cin >> N >> M;

    dfs((vector<int>){});

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}