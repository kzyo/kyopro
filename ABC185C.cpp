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
    int L;
    cin >> L;

    int div = 1;
    REP(i,12)
    {
        int n = i+1;

        div *= n;
    }

    unsigned ll ans = 1;
    REP(i, 12)
    {
        ans *= L -i;
    }

    ans /= div;

    cout << ans << endl;
    
    return 0;
}