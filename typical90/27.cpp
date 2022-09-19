#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

int main()
{
    ll N;
    cin >> N;

    map<string, int> m;

    for (ll i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        if (m[s] == 0)
        {
            cout << i << endl;
            m[s]++;
        }
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}