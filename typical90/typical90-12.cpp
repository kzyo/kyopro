#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

int H, W;

int pos(int r, int c)
{
    return r * (W + 2) + c;
}

int main()
{

    cin >> H >> W;
    vector isRed(H + 2, vector<bool>(W + 2, false));
    dsu d((H + 2) * (W + 2));

    int Q;
    cin >> Q;
    REP(i, Q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int r, c;
            cin >> r >> c;
            isRed[r][c] = true;
            if (isRed[r - 1][c])
                d.merge(pos(r - 1, c), pos(r, c));
            if (isRed[r][c - 1])
                d.merge(pos(r, c - 1), pos(r, c));
            if (isRed[r + 1][c])
                d.merge(pos(r + 1, c), pos(r, c));
            if (isRed[r][c + 1])
                d.merge(pos(r, c + 1), pos(r, c));
        }
        else
        {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            if (isRed[r1][c1] && isRed[r2][c2] && d.same(pos(r1, c1), pos(r2, c2)))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}