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
    ll N, K;
    cin >> N >> K;

    vector<ll> a(N);
    map<ll, ll> m;
    ll maxLen = -1;
    ll curLen = 0;
    ll numType = 0;

    REP(i, N)
    {
        cin >> a[i];

        curLen++;
        if (m[a[i]] == 0)
        {
            numType++;
        }
        m[a[i]]++;

        while (numType > K)
        {
            curLen--;
            m[a[i - curLen]]--;
            if (m[a[i - curLen]] == 0)
            {
                numType--;
            }
        }

        maxLen = max(maxLen, curLen);
    }

    cout << maxLen << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}