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
    ll N;
    cin >> N;

    string S;
    cin >> S;

    ll sp = -1;
    REP(i, S.size())
    {
        if (S[i] == 'p')
        {
            sp = i;
            break;
        }
    }

    if (sp < 0)
    {
        cout << S << endl;
        return 0;
    }

    string ans = S;

    for (ll r = sp; r < S.size(); r++)
    {
        string s = S.substr(sp, r - sp + 1);
        reverse(s.begin(), s.end());
        REP(i, s.size())
        {
            s[i] = s[i] == 'd' ? 'p' : 'd';
        }

        string ans2 = S.substr(0, sp) + s;
        if (r < S.size() - 1)
        {
            ans2 += S.substr(r + 1, S.size() - 1 - r);
        }

        ans = min(ans, ans2);
    }
    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}