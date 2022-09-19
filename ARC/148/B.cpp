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
    ll maxpnum = 0;
    vector<ll> maxpe(1, -1);
    ll count = 0;
    REP(i, S.size())
    {
        if (S[i] == 'p')
        {
            if (sp == -1)
                sp = i;
            count++;
            if (count > maxpnum)
            {
                maxpnum = count;
                maxpe = vector<ll>(1, i);
            }
            else if (count == maxpnum)
            {
                maxpe.push_back(i);
            }
        }
        else
        {
            count = 0;
        }
    }

    if (sp < 0)
    {
        cout << S << endl;
        return 0;
    }

    string ans = "";
    REP(i, S.size())
    {
        ans += 'p';
    }

    for (ll maxpee : maxpe)
    {
        string s = S.substr(sp, maxpee - sp + 1);
        reverse(s.begin(), s.end());
        REP(i, s.size())
        {
            s[i] = s[i] == 'd' ? 'p' : 'd';
        }

        string ans2 = S.substr(0, sp) + s;
        if (maxpee < S.size() - 1)
        {
            ans2 += S.substr(maxpee + 1, S.size() - 1 - maxpee);
        }

        ans = min(ans, ans2);
    }
    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}