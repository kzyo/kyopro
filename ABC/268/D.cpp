#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

vector<string> S, T;

string ans = "-1";
void solve(int pos, string curs, int remain)
{
    if (ans != "-1")
        return;

    if (pos == S.size())
    {
        if (curs.length() >= 3 && !binary_search(T.begin(), T.end(), curs))
        {
            ans = curs;
            return;
        }
        return;
    }

    if (pos == 0)
    {
        solve(pos + 1, S[0], remain);
        return;
    }

    if (curs.back() != '_')
    {
        solve(pos, curs + "_", remain);
        return;
    }

    solve(pos + 1, curs + S[pos], remain);
    if (remain > 0)
    {
        solve(pos, curs + "_", remain - 1);
        return;
    }

    return;
}

int main()
{
    ll N, M;
    cin >> N >> M;

    S = vector<string>(N);
    T = vector<string>(M);

    REP(i, N)
    cin >> S[i];
    sort(S.begin(), S.end());

    REP(i, M)
    cin >> T[i];
    sort(T.begin(), T.end());

    int remain = 16;
    REP(i, N)
    remain -= S[i].size();
    remain -= N - 1;

    do
    {
        solve(0, "", remain);
    } while (next_permutation(S.begin(), S.end()));

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}