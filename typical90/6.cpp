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
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    char pos[K];

    for (int i = 1; i <= K; i++)
    {
        pos[K - i] = s[N - i];
    }

    for (int i = N - K - 1; i >= 0; i--)
    {
        if (s[i] <= pos[0])
        {
            char tmp = pos[0];
            pos[0] = s[i];

            for (int j = 1; j < K; j++)
            {
                if (tmp <= pos[j])
                {
                    char t = pos[j];
                    pos[j] = tmp;
                    tmp = t;
                }
                else
                {
                    break;
                }
            }
        }
    }

    REP(i, K)
    {
        cout << pos[i];
    }
    cout << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}