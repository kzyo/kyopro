#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

ll A[100005];
ll N,K;
bool ok(ll m) {
    int count = 0;
    int pre = 0;
    REP(i, N+1) {
        int l = A[i] - pre;
        if (l >= m) {
            count++;
            pre = A[i];
            if (count > K) break;
        } 
    }

    return count > K;

}

int main()
{
    ll L;
    cin >> N >> L >> K;
    REP(i, N) { cin >> A[i];}
    A[N] = L;

    ll left = -1, right = L+1;

    while(right - left > 1) {
        ll middle = left + (right - left) / 2;
        if(ok(middle)) {
            left = middle;
        } else {
            right = middle;
        }
    }
    
    cout << left << endl;
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}