#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

int main()
{
    ll N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;
    
    ll initial = T - X * D;
    ll target = min(M, X);
    ll ans = initial + target * D;

    cout << ans << endl;
    
    return 0;
}