#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

int main()
{
    ll a, b, d;
    cin >> a >> b >> d;
    
    ld r = hypotl(a, b);
    ld rad = (ld)d * M_PI / (ld)180;
    ld theta = atan2l(b,a);

    ld ans_x = r * cosl(theta + rad);
    ld ans_y = r * sinl(theta + rad);
 
    cout << fixed << setprecision(20);
    cout << ans_x << " " << ans_y << endl;
    
    return 0;
}