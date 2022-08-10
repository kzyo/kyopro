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
    ll N;
    cin >> N;

    int M;
    cin >> M;

    vector<ll> v;
    ll min_s = 1100100100;

    vector<ll> nxt;
    REP(i, M)
    {
        ll nxtt;
        cin >> nxtt;
        nxt.push_back(nxtt);
    }
    sort(nxt.begin(), nxt.end());

    int now = 0;
    REP(i, M)
    {
        ll s = nxt[i] - now - 1;
        if (s!=0){ 
            min_s = min(s, min_s);
            v.push_back(s);
            }

        now = nxt[i];
    }
    ll s = N - now;
    if (s!=0)
    {
        min_s = min(s, min_s);
        v.push_back(s); 
    }
    int ans = 0;
    REP(i, v.size())
    {
        ans += v[i] / min_s;
    }
    
    cout << ans << endl;


    return 0;
}