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
    ll N, M;
    cin >> N >> M;

    vector<bool> pin(M + 1, true);
    pin[0] = false;

    ll ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ll a, b;
        cin >> a >> b;
        ll pinNo = i - a - b;
        if (0 < pinNo && pinNo <= M)
        {
            if (pin[pinNo] == true)
            {
                pin[pinNo] = false;
                ans++;
            }
        }
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}