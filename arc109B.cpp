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
  long long n;
  cin >> n;
  
  ll nn = 0;
  long long x = nn;
  
  while(2*n>=nn*nn+nn - 2)
  {
    x = nn;
    nn++;
  }
  
  cout << n - (x - 1) << endl; 
    
    return 0;
}