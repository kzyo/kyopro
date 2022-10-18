#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define ll int
#define ld long double

#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)

using namespace std;

ll H, W, sh, sw;
ll N;
ll Q;
map<ll, vector<ll>> amp, bmp;
int main()
{

    cin >> H >> W >> sh >> sw;

    cin >> N;
    REP(i, N)
    {
        ll h, w;
        cin >> h >> w;

        amp[h].push_back(w);
        bmp[w].push_back(h);
    }

    for (auto &v : amp)
    {
        sort(v.second.begin(), v.second.end());
    }
    for (auto &v : bmp)
    {
        sort(v.second.begin(), v.second.end());
    }

    cin >> Q;
    char d;
    ll l;
    REP(i, Q)
    {

        cin >> d >> l;

        if (d == 'L')
        {
            auto a = amp.find(sh);
            ll okw = 0;
            if (a != amp.end())
            {
                auto &v = a->second;
                auto it = lower_bound(v.begin(), v.end(), sw);
                if (it != v.begin())
                {
                    it--;
                    okw = *it;
                }
            }
            sw = max(sw - l, okw + 1);
        }
        if (d == 'U')
        {
            auto a = bmp.find(sw);
            ll okh = 0;
            if (a != bmp.end())
            {
                auto &v = a->second;
                auto it = lower_bound(v.begin(), v.end(), sh);
                if (it != v.begin())
                {
                    it--;
                    okh = *it;
                }
            }
            sh = max(sh - l, okh + 1);
        }
        if (d == 'R')
        {
            auto a = amp.find(sh);
            ll okw = W + 1;
            if (a != amp.end())
            {
                auto &v = a->second;
                auto it = upper_bound(v.begin(), v.end(), sw);
                if (it != v.end())
                {
                    okw = *it;
                }
            }
            sw = min(sw + l, okw - 1);
        }

        if (d == 'D')
        {
            auto a = bmp.find(sw);
            ll okh = H + 1;
            if (a != bmp.end())
            {
                auto &v = a->second;
                auto it = upper_bound(v.begin(), v.end(), sh);
                if (it != v.end())
                {
                    okh = *it;
                }
            }
            sh = min(sh + l, okh - 1);
        }

        cout << sh << ' ' << sw << endl;
    }

    return 0;
}