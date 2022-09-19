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
    vector<ll> a(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<string> s(3);
    REP(i, 3)
    {
        s[i] = to_string(a[N - 1 - i]);
    }
    sort(s.begin(), s.end());
    RREP(i, 3)
    {
        cout << s[i];
    }
    cout << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}