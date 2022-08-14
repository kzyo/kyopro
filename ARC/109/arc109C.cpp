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

char winner(char c1, char c2)
{
  switch(c1)
  {
    case 'R':
      if (c2 == 'P') c1 =c2;
      break;
    case 'P':
      if (c2 == 'S') c1 =c2;
      break;
    case 'S':
            if (c2 == 'R') c1 =c2;
      break;
    default:
      cout << "yaba yaba swww" << endl;
      break;
  }
  
  return c1;
}
 
int main()
{
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  
  REP(i,k)
  {
      s = s+s;
    string ts = "";
    int len = s.length();
    int loop = len/2;
    REP(j,loop)
    {
      char c1,c2;
      c1 = s[j*2];
      c2 = s[j*2+1];
      ts += winner(c1,c2);
    }
    if(ts.length()>0)s = ts;
  }
  
  cout << s[0] << endl;
  
  return 0;
}