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
    int N,M;
    cin >> N >> M;

    ll cash = N;
    ll point = 0;
    REP(i, M)
    {
        int p;
        cin >> p;

        if(point >= p)
        {
            point -= p;
        }
        else
        {
            cash -= p;
            point += p*0.1;
        }
        
        cout << cash << " " << point << endl;
    }
    
    return 0;
}