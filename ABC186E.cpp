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
    int T;
    cin >> T;

    REP(t,T)
    {
        ll N,S,K;
        cin >> N >> S >> K;

        if ((N-S)%K == 0)
        {
            cout << (N-S)/K << endl;
            continue;
        }

        ll ans = 0;
        ll div = N/K;
        ll mov = N%K;
        if (div==0)
        {
            cout << -1 << endl;
            continue;
        }


        ll s = -S;
        while(true)
        {
            ans += div;

            s += mov;
            if(s%K==0)
            {
                ans+= s/K;
                break;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}