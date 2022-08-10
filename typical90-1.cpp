#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

int N, L, K;
int* a;

int main()
{

    cin >> N >> L >> K;

    int A[N+1];
    REP(i, N) {
        cin >> A[i];
    }
    A[N] = L;

    int a[N+1];
    ll ans = A[0];
    a[0] = A[0];
    REP(i, N) {
        a[i+1] = A[i+1] - A[i];
        ans = min(ans, (ll)a[i+1]);
    }

    int cand = L / 2;
    int l = 0, r = L;

    while(true) {
        int cnt = 0;
        ll total = 0;
        ll now_min = INT64_MAX;
        bool ok = false;

        REP(i, N+1) {
            total += a[i];
            if (total > cand) {
                now_min = min(now_min, total);
                cnt++;
                if (cnt > K) {
                    ok = true;
                    break;
                }
                total = 0;
            }
        }

        int diff = 0;
        if (!ok) {
            r = cand;
            diff -= (cand - l) / 2;
        } else {
            ans = now_min;
            l = cand;
            diff += (r - cand) / 2;
        }
        cand += diff;
        if (diff == 0) break;
    }
    
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    cout << ans << endl;

    return 0;
}