#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

int main()
{
    string S;
    cin >> S;

    vector<ll> v(1000, 0);
    ll idx = 0;
    ll curNum = 0;

    map<ll, ll> m;

    for (char c : S)
    {
        if ('0' <= c && c <= '9')
        {
            ll num = c - '0';
            curNum *= 10;
            curNum += num;
            continue;
        }

        if (c == '(')
        {
            v[idx] = curNum;
            idx++;
            curNum = 0;
            continue;
        }

        if (c == ')')
        {
            idx--;
        }

        ll p = 1;
        for (int i = 0; i < idx; i++)
        {
            p *= v[i];
        }
        if (curNum != 0)
        {
            p *= curNum;
            curNum = 0;
        }
        m[c - 'a'] += p;
    }

    REP(i, 'z' - 'a' + 1)
    {
        cout << char('a' + i) << ' ' << m[i] << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}