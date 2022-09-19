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
    vector<ll> v(5);

    REP(i, 5)
    cin >> v[i];

    sort(v.begin(), v.end());
    auto i = unique(v.begin(), v.end());
    v.erase(i, v.end());

    cout << v.size() << endl;
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}