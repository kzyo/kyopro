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
    ll H, W;
    cin >> H >> W;

    if (H == 1 || W == 1)
    {
        cout << H * W << endl;
        return 0;
    }
    H = (H + 1) / 2;
    W = (W + 1) / 2;
    cout << H * W << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}