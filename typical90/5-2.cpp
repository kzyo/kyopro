#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define RREP(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

ll N,B,K;
vector<int> c;
ll dp[2][35];

int main()
{
    cin >> N >> B >> K;
    REP(i, K) {
        int t;
        cin >> t;
        c.push_back(t);
    }

    dp[0][0] = 1;
    REP(i, N) {
        REP(j, B) {
            for(int k: c) {
                ll num = (j * 10 + k) % B;
                dp[1][num] += dp[0][j];
                dp[1][num] %= 1000000007;
            }
        }
        REP(j, B) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }

    cout << dp[0][0] << endl;
    
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}