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
    int N,M;
    cin >> N >> M;

    ll A[1010], B[1010];

    REP(i, N) cin >> A[i];
    REP(i, M) cin >> B[i];

    int cost[M+1][N+1];
    REP(h,M+1)
    {
        REP(w, N+1)
        {
            if ( h==0) {cost[h][w]=w;continue;}

            if ( w== 0 ) {cost[h][w]=cost[h-1][w]+1;continue;}

            int a,b,c;
            a = cost[h][w-1] + 1;
            b = cost[h-1][w] + 1;
            c = cost[h-1][w-1] + 1;
            if (A[w-1] == B[h-1]) c--;
            cost[h][w] = min(a,b);
            cout << "cost: " << cost[h][w] << endl;
            cost[h][w] = min(c, cost[h][w]);
            cout << "a: " << a << "b: " << b << "c: " << c<<"cost: " <<cost[h][w]<<endl;
            
        }
    } 

    REP(i, M+1)
    {
        REP(j, N+1)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    cout << cost[M][N] << endl;
    return 0;
}