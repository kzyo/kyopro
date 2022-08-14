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
    int r, c;
    cin >> r >> c;
    int dist = abs(8 - r);
    dist = max(dist, abs(8 - c));

    if (dist % 2 == 0)
    {
        cout << "white" << endl;
    }
    else
    {
        cout << "black" << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}