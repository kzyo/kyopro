#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint1000000007;

ll H, W;
vector<vector<char>> C;

bool ok(vector<bool> pre, vector<bool> now, ll h)
{
    REP(i, W)
    {
        if (pre[i] == 1 && C[h - 1][i + 1] == '#')
            return false;
        if (now[i] == 1 && C[h][i + 1] == '#')
            return false;

        if (now[i] == 1 && C[h][i + 1] == '.')
        {
            if (pre[i] == 1)
                return false;
            if (i > 0)
            {
                if (pre[i - 1] == 1 || now[i - 1] == 1)
                    return false;
            }
            if (i < W - 1)
            {
                if (pre[i + 1] == 1 || now[i + 1] == 1)
                    return false;
            }
        }
    }
    return true;
}

int main()
{

    cin >> H >> W;

    C = vector(H + 2, vector<char>(W + 2, '.'));

    REP(i, H)
    {
        string s;
        cin >> s;
        REP(j, W)
        {
            C[i + 1][j + 1] = s[j];
        }
    }

    vector dp(H + 1, vector<mint>(1 << W, 0));
    dp[0][0] = 1;
    for (ll h = 1; h <= H; h++)
    {
        vector<bool> preBit(W);
        vector<bool> bit(W);
        REP(i, 1 << W)
        {
            REP(ii, W)
            preBit[ii] = ((i >> ii) % 2) == 1;
            REP(j, 1 << W)
            {
                REP(jj, W)
                bit[jj] = ((j >> jj) % 2) == 1;

                if (ok(preBit, bit, h))
                {
                    dp[h][j] += dp[h - 1][i];
                }
            }
        }
    }

    mint ans = 0;
    REP(i, 1 << W)
    ans += dp[H][i];

    cout << ans.val() << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}