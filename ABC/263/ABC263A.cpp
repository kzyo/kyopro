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
    vector<int> n(14, 0);
    REP(i, 5)
    {
        int t;
        cin >> t;
        n[t]++;
    }
    // REP(i, 14)
    // {
    //     cout << n[i] << endl;
    // }
    sort(n.begin(), n.end());

    // REP(i, 14)
    // {
    //     cout << n[i] << endl;
    // }

    if (n[13] == 3 && n[12] == 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}