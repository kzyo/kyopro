#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint1000000007;

mint ans = 1;
ll H, W;

void printC(vector<vector<char>> c)
{
    REP(i, H)
    {
        REP(j, W)
        {
            cout << c[i + 1][j + 1];
        }
        cout << endl;
    }
    cout << endl;
}

bool canSet(vector<vector<char>> c, ll h, ll w)
{
    if (c[h][w] != '.')
        return false;

    int dw[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dh[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    REP(i, 8)
    {
        if (c[h + dh[i]][w + dw[i]] == 'o')
            return false;
    }
    return true;
}

void solve(vector<vector<char>> c, ll h, ll w)
{
    if (w > W)
    {
        h++;
        w = 1;
    }
    if (h > H)
        return;

    // 置かないパターン
    solve(c, h, w + 1);

    if (canSet(c, h, w))
    {
        ans++;
        c[h][w] = 'o';
        // printC(c);
        solve(c, h, w + 1);
    }
}

int main()
{

    cin >> H >> W;

    vector C(H + 2, vector<char>(W + 2, '.'));

    REP(i, H)
    {
        string s;
        cin >> s;
        REP(j, W)
        {
            C[i + 1][j + 1] = s[j];
        }
    }

    solve(C, 1, 1);

    cout << ans.val() << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}