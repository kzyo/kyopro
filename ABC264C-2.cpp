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
    int h1, w1;
    cin >> h1 >> w1;
    vector a(h1, vector<int>(w1));
    REP(i, h1)
        REP(j, w1) cin >> a[i][j];

    int h2, w2;
    cin >> h2 >> w2;
    vector b(h2, vector<int>(w2));
    REP(i, h2)
        REP(j, w2) cin >> b[i][j];

    bool ok = false;
    REP(bh, 1 << h1)
    {
        REP(bw, 1 << w1)
        {
            vector<int> candh, candw;
            REP(i, h1)
            {
                if (bh >> i & 1)
                    candh.push_back(i);
            }
            REP(i, w1)
            {
                if (bw >> i & 1)
                    candw.push_back(i);
            }

            if (candh.size() != h2 || candw.size() != w2)
                continue;

            vector c(h2, vector<int>(w2));
            REP(i, h2)
            REP(j, w2) c[i][j] = a[candh[i]][candw[j]];

            if (b == c)
            {
                ok = true;
                break;
            }
        }
        if (ok)
            break;
    }

    if (ok)
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