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
   ll N, Q;
   cin >> N >> Q;
   int A[300300];

   REP(i, N) cin >> A[i];

   REP(i, Q)
   {
       int t,x,y;
       cin >>t >> x >> y;
       x++;
       if(t==1)
       {
           A[x] ^= y;

       }else
       {
           int out = A[x];
           while(x<y)
           {
               x++;
               out ^= A[x];
           }
           cout << out << endl;
       }
       
   } 
    return 0;
}