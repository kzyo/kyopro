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

    vector<ll> A(N), v(N);
    REP(i, N)
    {
        cin >> A[i];
        v[i] = A[i];
    }

    sort(v.begin(), v.end());
    auto i = unique(v.begin(), v.end());
    v.erase(i, v.end());

    map<ll, ll> num;
    REP(i, v.size())
    {
        num[v[i]] = v.size() - 1 - i;
    }

    map<ll, ll> ans;
    REP(i, N)
    {
        ans[num[A[i]]] += 1;
    }

    REP(i, N)
    {
        cout << ans[i] << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}