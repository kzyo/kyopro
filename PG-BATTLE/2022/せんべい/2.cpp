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

    vector<pair<ll, ll>> a;
    for (ll i = 1; i <= 3 * N; i++)
    {
        ll A;
        cin >> A;
        a.push_back(make_pair(A, i));
    }
    sort(a.begin(), a.end());

    vector<ll> ans;
    for (ll i = N; i < 2 * N; i++)
    {
        ans.push_back(a[i].second);
    }
    sort(ans.begin(), ans.end());

    REP(i, N)
    {
        cout << ans[i] << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}