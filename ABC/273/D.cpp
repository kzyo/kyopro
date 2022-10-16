#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

ll M = 1000000000;
map<int, int> m;
int main()
{
    ll H, W;
    cin >> H >> W;

    ll sh, sw;
    cin >> sh >> sw;

    ll N;
    cin >> N;

    vector<vector<int>> v(200005);
    int idx = 1;
    REP(i, N)
    {
        ll r, c;
        cin >> r >> c;
        if (m[r] == 0)
        {
            m[r] = idx;
            v[idx].push_back(c);
            idx++;
        }
        else
        {
            v[m[r]].push_back(c);
        }
    }

    REP(i, idx - 1)
    {
        sort(v[idx + 1].begin(), v[idx + 1].end());
    }

    int dh[] = {-1, 0, 0, 1};
    int dw[] = {0, -1, 1, 0};
    map<char, int> dd;
    dd['U'] = 0;
    dd['L'] = 1;
    dd['R'] = 2;
    dd['D'] = 3;

    ll Q;
    cin >> Q;

    char d;
    ll n;
    ll th;
    ll tw;
    REP(i, Q)
    {

        cin >> d >> n;

        REP(j, n)
        {
            th = sh + dh[dd[d]];
            tw = sw + dw[dd[d]];
            if (th < 1)
                break;
            if (tw < 1)
                break;
            if (th > H)
                break;
            if (tw > W)
                break;

            if (!m[th * M + tw])
            {
                sh = th;
                sw = tw;
            }
            else
            {
                break;
            }
        }

        cout << sh << ' ' << sw << endl;
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}