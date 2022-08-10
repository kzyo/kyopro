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

ll ans;
ll ta;

bool check(int n)
{
  bool ret = true;
    REP(i, n)
  {
    if(i==0)continue;
    int ii = i+1;
    if (ta % ii != 0) {ret = false; break;}
  }
  
  return ret;

}

int main()
{
    int n;
    cin >> n;

    ans = n;
    for(int i=n-1;i>=2;i--)
    {
        if (ans % i != 0) ans *= i;
    }
    

  	while(ans > 10000000000000-1)
    {
      REP(i,n)
      {
        if(i==0)continue;
        int ii = i+1;
        ta = ans / ii;
        if (check(n)) {ans = ta; 
                       //cout << "ans: "<< ans << endl;
                      }
      }
    }
  ans ++;
    cout << ans << endl;
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
    int n;
    cin >> n;

    ans = n;
 
 
 
 
    
    
    return 0;
}