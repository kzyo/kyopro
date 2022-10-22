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

    ll n2 = 1;
    REP(i, N)
    n2 *= 2;
    vector<pair<ll, ll>> a(n2);
    REP(i, n2)
    {
        ll num;
        cin >> num;
        a[i] = make_pair(num, i + 1);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    vector<ll> ans(n2);

    ll num = n2;
    ll diff = 2;
    ll offset = 0;
    ll idx = 0;
    bool ok = true;
    while (diff <= n2)
    {
        REP(i, n2 / diff)
        {
            if (a[idx].first != num)
            {
                ok = false;
                break;
            }
            ans[i * diff + offset] = a[idx].second;
            idx++;
        }

        offset = diff - 1;
        diff *= 2;
        num /= 2;
    }

    if (ok && a[a.size() - 1].first == 1)
    {
        REP(i, ans.size() - 1)
        {
            cout << ans[i] << ' ';
        }
        cout << a[a.size() - 1].second << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}