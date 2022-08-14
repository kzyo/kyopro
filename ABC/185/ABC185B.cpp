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
    int N,M,T;
    cin >> N >> M >> T;
    
    int now = N;
    int pre = 0;
    bool ok = true;

    REP(i, M)
    {
        int a, b;
        cin >> a >> b;

        now -= a - pre;
        if (now <= 0)
        {
            ok = false;
            break;
        }
        
        now += b -a;
        if (now > N) now = N;
        
        pre = b;
    }

    now -= T - pre;
    if (now <= 0) ok = false;

    if(ok)
    {
        cout << "Yes" << endl;
    }
    else 
    {
        cout << "No" << endl;
    }

    return 0;
}