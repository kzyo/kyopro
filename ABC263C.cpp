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
    int N, M;
    cin >> N >> M;

    int a[N];
    REP(i, N)
    a[i] = i + 1;

    bool finished = false;
    while (!finished)
    {
        if (a[N - 1] <= M)
        {
            REP(i, N)
            {
                cout << a[i];
                if (i == N - 1)
                    break;
                cout << " ";
            }
            cout << endl;
        }

        int target = N - 1;
        while (true)
        {
            if (target < 0)
            {
                finished = true;
                break;
            }
            a[target]++;
            if (a[target] > M)
            {
                target--;
                continue;
            }

            bool continuee = false;
            for (int i = target + 1; i < N; i++)
            {
                a[i] = a[i - 1] + 1;
                if (a[i] > M)
                {
                    target--;
                    if (target < 0)
                    {
                        finished = true;
                        break;
                    }
                    continuee = true;
                    break;
                }
            }
            if (!continuee)
                break;
        }
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}