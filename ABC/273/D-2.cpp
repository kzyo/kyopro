#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

int main()
{
    ll H, W, sh, sw;
    cin >> H >> W >> sh >> sw;

    map<ll, vector<ll>> mh, mw;
    ll N;
    cin >> N;
    REP(i, N)
    {
        ll h, w;
        cin >> h >> w;

        mh[h].push_back(w);
        mw[w].push_back(h);
    }

    for (auto v : mh)
    {
        sort(v.second.begin(), v.second.end());
    }
    for (auto v : mw)
    {
        sort(v.second.begin(), v.second.end());
    }

    ll Q;
    cin >> Q;
    REP(i, Q)
    {
        char d;
        ll l;
        cin >> d >> l;

        if (d == 'L')
        {
            vector<ll> v = mh[sh];
            ll okw = 0;
            if (v.size() > 0)
            {
                auto it = lower_bound(v.begin(), v.end(), sw);
                if (it != v.begin())
                {
                    it--;
                }
                if (*it < sw)
                    okw = *it;
            }
            sw = max(sw - l, okw + 1);
        }

        if (d == 'R')
        {
            vector<ll> v = mh[sh];
            ll okw = W + 1;
            if (v.size() > 0)
            {
                auto it = upper_bound(v.begin(), v.end(), sw);
                if (it != v.end())
                {
                    okw = *it;
                }
            }
            sw = min(sw + l, okw - 1);
        }

        if (d == 'U')
        {
            vector<ll> v = mw[sw];
            ll okh = 0;
            if (v.size() > 0)
            {
                auto it = lower_bound(v.begin(), v.end(), sh);
                if (it != v.begin())
                {
                    it--;
                }
                if (*it < sh)
                    okh = *it;
            }
            sh = max(sh - l, okh + 1);
        }

        if (d == 'D')
        {
            vector<ll> v = mw[sw];
            ll okh = H + 1;
            if (v.size() > 0)
            {
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

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}