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
    int N;
    cin >> N;

    vector<int> A(N);
    REP(i, N)
    cin >> A[i];
    sort(A.begin(), A.end());

    int Q;
    cin >> Q;
    REP(hoge, Q)
    {
        int B;
        cin >> B;
        auto pos = upper_bound(A.begin(), A.end(), B);
        int idx = distance(A.begin(), pos);
        int ans = abs(B - A[idx]);
        if (idx > 0)
            ans = min(ans, abs(B - A[idx - 1]));
        cout << ans << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}