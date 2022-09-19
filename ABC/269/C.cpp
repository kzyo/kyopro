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

    vector<unsigned ll> v;
    REP(i, 60)
    {
        if (((N >> i) & 1) == 1)
        {
            v.push_back((unsigned ll)1 << i);
        }
    }

    REP(i, 1 << v.size())
    {
        unsigned ll out = 0;
        REP(j, 60)
        {
            if (((i >> j) & 1) == 1)
            {
                out += v[j];
            }
        }
        cout << out << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}