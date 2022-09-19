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

    ll A[N];
    REP(i, N)
    {
        cin >> A[i];
    }
    ll B[N];
    REP(i, N)
    {
        cin >> B[i];
    }

    ll diff = 0;
    REP(i, N)
    {
        diff += abs(A[i] - B[i]);
    }

    K -= diff;
    if (K >= 0 && K % 2 == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}