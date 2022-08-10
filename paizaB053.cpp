#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

int main()
{
    int H, W;
    cin >> H >> W;
    
    int ans[H][W];
    REP(h, H)
    {
        REP(w, W)
        {
            ans[h][w] = -1;
        }
    }
    
    cin >> ans[0][0] >> ans[0][1];
    cin >> ans[1][0] >> ans[1][1];

    REP(h, H)
    {
        if (ans[h][0] == -1)
        {
            ans[h][0] = 2*ans[h-1][0] - ans[h-2][0];
            ans[h][1] = 2*ans[h-1][1] - ans[h-2][1];
        }

        REP(w, W)
        {
            if(ans[h][w] == -1) ans[h][w] = ans[h][w-1] * 2 - ans[h][w-2];
            cout << ans[h][w];
            if (w!=W-1) cout << ' ';
        }
        cout << endl;
    }
    
    return 0;
}