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

int score(int* num, int len)
{
    int nn[len-1];

    if(len == 1) return num[0];

    REP(i, len)
    {
        if (i==0) continue;

        nn[i-1] = num[i] + num[i-1];
        if(nn[i-1] > 101) nn[i-1] -= 101;
    }
 
    return score(nn, len - 1);
}

void getNum(string s, int* num)
{
    int len = s.length();

    REP(i, len)
    {
        num[i] = s[i] - 'a' + 1;
    }
}

int main()
{
    string a,b;
    cin >> a >> b;

    string t = a+b;
    int num[t.length()];
    getNum(t, num);
    int ans = score(num, t.length());

    t = b+a;
    getNum(t, num);
    ans = max(ans, score(num, t.length()));

    cout << ans << endl;
    
    return 0;
}