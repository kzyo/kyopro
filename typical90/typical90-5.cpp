#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define RREP(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;

ll N,B,K;
bool c[10];

bool isOK(ll num) {
    if (num % B != 0) return false;
    while(num > 0) {
        int m = num % 10;
        if (!c[m]) return false; 
        num /= 10;
    }

    return true;
}

int main()
{
    cin >> N >> B >> K;
    REP(i, K) {
        int t;
        cin >> t;
        c[t] = true;
    }

    ll lowest = 1;
    REP(i, N-1) {
        lowest *= 10;
    }
    ll highest = lowest * 10;

    ll cnt = 0;
    for(ll i = lowest; i < highest; i++) {
        if(isOK(i)) {
            cnt++;
            cnt %= 1000000007;
        }
    }

    cout << cnt << endl;
    
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}