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
    ll a, b;
    cin >> a >> b;
    ll gc = gcd(a, b);
    ll inf = powl(10, 18);

    if (inf / a < b / gc)
    {
        cout << "Large" << endl;
    }
    else
    {
        cout << b / gc * a << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}