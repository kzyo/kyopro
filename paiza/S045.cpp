#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

int main()
{
    int N;
    cin >> N;

    int A[N + 1];
    int diff[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        diff[i] = A[i] - i;
    }

    int minIdx = 1, maxIdx = N;
    for (int i = minIdx; i <= N; i++)
    {
        if (diff[i] != 0)
        {
            minIdx = i;
            break;
        }
    }

    for (int i = maxIdx; i >= 0; i--)
    {
        if (diff[i] != 0)
        {
            maxIdx = i;
            break;
        }
    }

    int ans = 0;
    while (minIdx < maxIdx)
    {
        ans++;
        int max = -1, maxi = -1;
        for (int i = minIdx; i <= maxIdx; i++)
        {
            if (abs(diff[i]) > max)
            {
                max = abs(diff[i]);
                maxi = i;
            }
        }

        if (diff[maxi] < 0)
        {
            REP(j, max)
            {
                diff[maxi - j] = diff[maxi - j - 1] - 1;
            }
            diff[maxi - max] = 0;
            for (int i = minIdx; i <= maxIdx; i++)
            {
                if (diff[i] != 0)
                {
                    minIdx = i;
                    break;
                }
                if (i == maxIdx)
                    minIdx = maxIdx;
            }
        }
        else
        {
            REP(j, max)
            {
                diff[maxi + j] = diff[maxi + j + 1] + 1;
            }
            diff[maxi + max] = 0;

            for (int i = maxIdx; i >= minIdx; i--)
            {
                if (diff[i] != 0)
                {
                    maxIdx = i;
                    break;
                }
                if (i == minIdx)
                    maxIdx = minIdx;
            }
        }
    }

    cout << ans << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}