#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)

ll gx[3], gy[3];
ll x[3] = {0, 1, 0};
ll y[3] = {0, 0, 1};

bool matched[3]{false};
bool matchedg[3]{false};

bool finished()
{
    bool ret = true;

    REP(i, 3)
    ret &= matched[i];

    return ret;
}

ld move(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll *tx, ll *ty)
{
}

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ld mgx = (gx[0] + gx[1] + gx[2]) / (ld)3;
        ld mgy = (gy[0] + gy[1] + gy[2]) / (ld)3;

        ll tx[3], ty[3];
        ld diff[3];

        ll cnt = 0;

        while (!finished())
        {
            REP(i, 3)
            diff[i] = move(x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3], x[(i + 2) % 3], y[(i + 2) % 3], &tx[i], &ty[i]);
            int idx = -1;
            ld min = numeric_limits<ld>::max();

            if (min > diff[0] && !matched[0])
                idx = 0;
            if (min > diff[1] && !matched[1])
                idx = 1;
            if (min > diff[2] && !matched[2])
                idx = 2;

            x[idx] = tx[idx];
            y[idx] = ty[idx];

            REP(i, 3)
            if (!matchedg[i] && x[idx] == gx[i] && y[idx] == gy[i])
            {
                matchedg[i] = true;
                matched[idx] = true;
                break;
            }

            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}