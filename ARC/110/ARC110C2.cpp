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

int main()
{
    int n;
    cin >> n;

    int v[200100];
    int pos[200100];
    int ans[200100];
    int ansidx = 0;
    bool used[200100] {false};

    REP(i, n)
    {
        cin >> v[i];
        pos[v[i]] = i;
    }

    int lasti = n;
    int si = 1;
    for(int num = 1; num <= n; num++)
    {
        if (pos[num] == num - 1)
            continue;
        int i = pos[num];
        while (i > num - 1)
        {
            if (used[i])
            {
                cout << -1 << endl;
                return 0;
            }

            used[i] = true;
            ans[ansidx++] = i;
            int t = v[i];
            v[i] = v[i - 1];
            v[i - 1] = t;
            t = pos[i];
            pos[i] = pos[i - 1];
            pos[i - 1] = t;
            i--;
        }
    }
    int last = n - 1;
    //REP(i,last) cout << ans[i] << endl;

    if (ansidx != n - 1)
    {
        cout << -1 << endl;
        return 0;
    }

    REP(i, last)
    cout << ans[i] << endl;

    return 0;
}