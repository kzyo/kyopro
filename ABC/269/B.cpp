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
    vector<string> S(10);
    REP(i, 10)
    cin >> S[i];

    ll si = -1, ei = -1, sj = -1, ej = -1;
    REP(i, 10)
    {
        string s = S[i];
        REP(j, 10)
        {
            char c = s[j];
            if (c == '.')
                continue;
            ei = i;
            ej = j;
            if (si == -1)
                si = i;
            if (sj == -1)
                sj = j;
        }
    }
    cout << (si + 1) << " " << (ei + 1) << endl;
    cout << (sj + 1) << " " << (ej + 1) << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}