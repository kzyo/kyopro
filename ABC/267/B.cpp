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

    vector<ll> v(s.length() + 1);
    for (ll i = 1; i <= s.length(); i++)
    {
        v[i] = s[i - 1];
    }

    vector<bool> row(7, false);
    if (v[7] == '0')
        row[0] = true;
    if (v[4] == '0')
        row[1] = true;
    if (v[2] == '0' && v[8] == '0')
        row[2] = true;
    if (v[1] == '0' && v[5] == '0')
        row[3] = true;
    if (v[3] == '0' && v[9] == '0')
        row[4] = true;
    if (v[6] == '0')
        row[5] = true;
    if (v[10] == '0')
        row[6] = true;

    ll count = 0;
    bool now = true;
    REP(i, 7)
    {
        if (now != row[i])
        {
            count++;
            now = row[i];
        }
    }

    if (count >= 3 && v[1] == '0')
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