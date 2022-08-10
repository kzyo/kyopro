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
    int N;
    cin >> N;

    int c10 = 0;
    int c8 = 0;
    int ans = 0;
    REP(i,N)
    {
        c10++;c8++;ans++;

        if(c10==7||c8==7)ans--;

        if(c8==8)c8=0;
        if(c10=10)c10=0;

    }
    
    cout << ans << endl;
    return 0;
}