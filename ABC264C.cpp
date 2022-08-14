#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

vector<vector<int>> candh;
void dfsh(vector<int> n, int delNum, int maxNum)
{

    if (n.size() == delNum)
    {
        vector<int> t;
        copy(n.begin(), n.end(), back_inserter(t));
        candh.push_back(t);
        return;
    }

    int start = 0;
    if (n.size() > 0)
        start = n.back() + 1;

    for (int num = start; num < maxNum; num++)
    {
        vector<int> new_n(n.size());
        copy(n.begin(), n.end(), new_n.begin());
        new_n.push_back(num);
        dfsh(new_n, delNum, maxNum);
    }
}

vector<vector<int>> candw;
void dfsw(vector<int> n, int delNum, int maxNum)
{

    if (n.size() == delNum)
    {
        vector<int> t;
        copy(n.begin(), n.end(), back_inserter(t));
        candw.push_back(t);
        return;
    }

    int start = 0;
    if (n.size() > 0)
        start = n.back() + 1;

    for (int num = start; num < maxNum; num++)
    {
        vector<int> new_n(n.size());
        copy(n.begin(), n.end(), new_n.begin());
        new_n.push_back(num);
        dfsw(new_n, delNum, maxNum);
    }
}

int main()
{
    int H, W;
    cin >> H >> W;
    vector A(H, vector<int>(W));
    REP(i, H)
    REP(j, W)
    {
        cin >> A[i][j];
    }

    int H2, W2;
    cin >> H2 >> W2;
    vector B(H2, vector<int>(W2));
    REP(i, H2)
    REP(j, W2)
    {
        cin >> B[i][j];
    }

    if (H2 > H || W2 > W)
    {
        cout << "No" << endl;
        return 0;
    }

    int diffh = H - H2;
    int diffw = W - W2;
    dfsh(vector<int>{}, diffh, H);
    dfsw(vector<int>{}, diffw, W);

    bool ok = false;
    for (auto delh : candh)
    {
        vector AA(H, vector<int>(W));
        copy(A.begin(), A.end(), AA.begin());
        reverse(delh.begin(), delh.end());
        for (int dh : delh)
        {
            AA.erase(AA.begin() + dh);
        }

        for (auto delw : candw)
        {
            bool nxt = false;
            REP(i, H2)
            {
                int aaj = -1;
                int delidx = 0;
                REP(j, W2)
                {
                    aaj++;
                    if (delw.size() > 0)
                    {
                        while (aaj == delw[delidx])
                        {
                            aaj++;
                            delidx++;
                        }
                    }
                    if (AA[i][aaj] != B[i][j])
                    {
                        nxt = true;
                        break;
                    }
                }
                if (nxt)
                    break;
            }
            if (!nxt)
            {
                ok = true;
                break;
            }
            if (ok)
                break;
        }
        if (ok)
            break;
    }

    // bool ok = true;
    // int noww = 0;
    // while (noww < A[0].size() && noww < B[0].size())
    // {
    //     if (A[0][noww] == B[0][noww])
    //     {
    //         noww++;
    //     }
    //     else
    //     {
    //         REP(h, H)
    //         {
    //             A[h].erase(A[h].begin() + noww);
    //         }
    //     }
    // }

    // int nowh = 0;
    // while (nowh < A.size() && nowh < B.size())
    // {
    //     if (A[nowh][0] == B[nowh][0])
    //     {
    //         nowh++;
    //     }
    //     else
    //     {
    //         A.erase(A.begin() + nowh);
    //     }
    // }

    // if (A.size() != B.size() || A[0].size() != B[0].size())
    // {
    //     cout << "No" << endl;
    //     return 0;
    // }

    // REP(i, H2)
    // REP(j, W2)
    // {
    //     if (A[i][j] != B[i][j])
    //     {
    //         ok = false;
    //     }
    // }

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