#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

/*
  startNum ~ endNumからselectNum個選んだ組み合わせを返す
*/
void _combination(vector<int> tmp, vector<vector<int>> *combinations, int selectNum, int startNum, int endNum);

vector<vector<int>> combination(int selectNum, int startNum, int endNum)
{
    vector<vector<int>> combinations;
    _combination(vector<int>{}, &combinations, selectNum, startNum, endNum);
    return combinations;
}

void _combination(vector<int> tmp, vector<vector<int>> *combinations, int selectNum, int startNum, int endNum)
{

    if (tmp.size() == selectNum)
    {
        (*combinations).push_back(tmp);
        return;
    }

    int start = startNum;
    if (tmp.size() > 0)
        start = tmp.back() + 1;

    int idx = tmp.size();
    tmp.resize(tmp.size() + 1);
    for (int num = start; num <= endNum; num++)
    {
        tmp[idx] = num;
        _combination(tmp, combinations, selectNum, startNum, endNum);
    }
}

int main()
{
    int h1, w1;
    cin >> h1 >> w1;
    vector a(h1, vector<int>(w1));
    REP(i, h1)
    REP(j, w1)
    cin >> a[i][j];

    int h2, w2;
    cin >> h2 >> w2;
    vector b(h2, vector<int>(w2));
    REP(i, h2)
    REP(j, w2)
    cin >> b[i][j];

    bool ok = false;
    auto candhs = combination(h2, 0, h1 - 1);
    auto candws = combination(w2, 0, w1 - 1);
    for (auto candh : candhs)
    {
        for (auto candw : candws)
        {
            vector c(h2, vector<int>(w2));
            REP(i, h2)
            REP(j, w2)
            c[i][j] = a[candh[i]][candw[j]];

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