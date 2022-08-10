#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

ll H, W;
ll A[2010][2010];

int main()
{
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }

    ll h[H], w[W];
    REP(i, H) {
        ll tmp = 0;
        REP(j, W) {
            tmp += A[i][j];
        }
        h[i] = tmp;
    }

    REP(i, W) {
        ll tmp = 0;
        REP(j, H) {
            tmp += A[j][i];
        }
        w[i] = tmp;
    }

    REP(i, H) {
        REP(j, W) {
            cout << h[i] + w[j] - A[i][j];
            if (j < W - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}