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
  int p = 1;
  int hoge;cin >> hoge;
    string s;
    cin >> s;
  
  if (s[0] == '1' && s[1] == '0' ) s = "1" + s;
    if (s[0] == '0' ) s="11"+s;

  int len = s.length();
  if(len==1)
  {
    if (s == "1") p = 2;
    if (s == "0" || s == "1") s = "110";
  }
  else
  {
    if (s[len-1] == '1' && s[len -2] == '0') s = s + "10";
    if (s[len-1] == '1' && s[len -2] == '1') s = s + "0";
  }
  
  
    len = s.length();
    if (len % 3 != 0){cout <<0<<endl;return 0;}
    len /= 3;
    int n = 0;
    REP(i, len)
    {
        if (s[3*i]=='1'&&s[3*i+1]=='1'&&s[3*i+2]=='0')
        {
            n++;
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }

  	ll ans = pow(10,10);
  	--n;
  ans -= n;
  ans *=p;
    cout <<  ans << endl;
    return 0;
}