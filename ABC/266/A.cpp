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
    ll l = s.length();

    cout << s[l / 2] << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}