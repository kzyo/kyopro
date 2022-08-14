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
    string s;
    cin >> s;
    ll ans = 0;
    string ss = "atcoder";
    REP(ii, ss.length())
    {
        char c = ss[ii];
        int idx = 0;
        for (int i = ii; i < ss.length(); i++)
        {
            if (s[i] == c)
            {
                idx = i;
                break;
            }
        }
        RREP(i, idx + 1)
        {
            if (i == ii)
                break;
            ans++;
            swap(s[i], s[i - 1]);
        }
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}