#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint1000000007;

int main()
{
    int N;
    cin >> N;

    string S;
    cin >> S;

    map<char, int> converter;
    // converter['a'] = 0;
    converter['t'] = 1;
    converter['c'] = 2;
    converter['o'] = 3;
    converter['d'] = 4;
    converter['e'] = 5;
    converter['r'] = 6;

    vector dp(7, vector<mint>(N, 0));

    if (S[0] == 'a')
        dp[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        REP(j, 7)
        {
            dp[j][i] = dp[j][i - 1];
        }
        char c = S[i];
        if (c == 'a')
        {
            dp[0][i]++;
        }
        else if (converter[c] != 0)
        {
            dp[converter[c]][i] += dp[converter[c] - 1][i - 1];
        }
    }

    // REP(j, 7)
    // {
    //     REP(i, N)
    //     {
    //         cout << dp[j][i].val() << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[6][N - 1].val() << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}