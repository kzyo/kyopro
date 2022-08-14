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
    int Y;
    cin >> Y;
    int mod = Y % 4;
    if (mod == 3) Y += 3;
    if (mod == 0) Y += 2;
    if (mod==1) Y += 1;
    cout << Y;
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}