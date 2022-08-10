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
    if ((N % 2) != 0) {
        return 0;
    }

    REP(i, 1<<N){
        int num[N];
        int tmp=i;
        RREP(i,N){
            num[i] = tmp % 2;
            tmp /= 2;
        }

        bool ok = true;
        int cnt[2] = {0,0};
        REP(i,N){
            cnt[num[i]] += 1;
            if(cnt[1] > cnt[0]) {
                ok = false;
                break;
            }
        }
        if (cnt[0] != cnt[1]) ok = false;
        if (ok) {
            REP(i,N){
                if(num[i]==0) {
                    cout << '(';
                } else {
                    cout << ')';
                }
            }
            cout << endl;
        }
    }
    
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}