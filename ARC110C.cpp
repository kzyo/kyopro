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
    int n;

    int v[100100];
    bool used[100100] {false};
    int ans[100100];
    int ansidx =0;

    REP(i, n) 
    {
        cin >> v[i];
    }

    for(int i=n;i>0;i--)
    {
        int idx;
        for(idx=0;idx<n;idx++) if(v[idx] == i) break;
        int last = i-1;
        for(idx++;idx<last;idx++)
        {
            if(used[idx])
            {
                cout << -1 << endl;
                return 0;
            }
            ans[ansidx++] = idx;
            used[idx] = true;
            int t = v[idx];
            v[idx] = v[idx-1];
            v[idx-1] = t;
        }
    }

    for(int i=1;i<=n;i++) if(v[i-1] != i) {cout << -1 << endl; return 0;}

    REP(i,n-1) cout << ans[i] << endl;

    return 0;
}