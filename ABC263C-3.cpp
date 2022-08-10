#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

void p(int *a, int N)
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

bool init(int *a, int N, int M, int start_pos)
{
    for (int i = start_pos; i < N; i++)
    {
        a[i] = a[i - 1] + 1;
        if (a[i] > M)
        {
            return false;
        }
    }

    return true;
}

bool countUp(int *a, int N, int M)
{
    int target = N - 1;
    while (true)
    {
        if (target < 0)
        {
            return false;
        }
        a[target]++;
        if (a[target] > M)
        {
            target--;
            continue;
        }

        bool completed = init(a, N, M, target + 1);

        if (completed)
        {
            break;
        }
        else
        {
            target--;
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    int a[N];
    REP(i, N)
    a[i] = i + 1;

    bool ok = true;
    while (ok)
    {
        p(a, N);
        ok = countUp(a, N, M);
    }

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}