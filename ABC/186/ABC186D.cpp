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
    int N;
    cin >> N;
    int A[N];
    REP(i,N) cin >> A[i];

    int diff[N];
    REP(i,N-1) diff[i] = A[i] - A[i+1];

    long long  diff2[N];
    ll adj = 0;
    REP(i,N-1)
    {
        if (i==0)
        {
            diff2[i] = 0;
            continue;
        }

        diff2[i] = diff2[i-1] + diff[i];
        adj += diff2[i];
    }

    long long  ans;
    return 0;
}