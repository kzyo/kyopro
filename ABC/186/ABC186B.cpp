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

int main()
{
    int H,W;
    cin >> H >> W;

    int minv =1000;

    int A[H][W];
    REP(h,H)
      REP(w,W)
      {
          cin >> A[h][w];
          minv = min(minv, A[h][w]);
      }

    int ans = 0;
    REP(h,H) REP(w,W) {ans+= A[h][w] - minv;}

    cout << ans << endl;

    return 0;
}