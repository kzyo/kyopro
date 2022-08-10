#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define RREP(i, n) for(long long i = (n) - 1; i >= 0; i--)

using namespace atcoder;


int main()
{
    int N;
 
    cin >> N;
   ll A[N+1];

    REP(i, N) {
        cin >> A[i + 1];
    }

    ll only = 0;
    ll cnt = 0;
    for(int i =1;i<=N;i++){
        if (A[i] == i) {
            only++;
            continue;
        }
        if (A[A[i]] == i) cnt++;
    }
    only--;
    only = (1 + only) * only / 2;
    cout << only + cnt/2 << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}