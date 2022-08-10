#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define RREP(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

ll mod[110][110];

int main()
{
    ll N;
    cin >> N;

    mod[1][0] = N;
    REP(i, N) {
        ll a;
        cin >> a;
        for (int i=2;i++;i<=N) {
            mod[i][a % i]++;
        }
    }
    
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}