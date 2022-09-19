#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for (long long i = 0; i < (n); i++)
#define RREP(i, n) for (long long i = (n)-1; i >= 0; i--)

using namespace atcoder;
using mint = modint998244353;

unsigned ll eightToten(string n)
{
    unsigned ll base = 1;
    unsigned ll ret = 0;
    REP(i, n.size())
    {
        char r = n[n.size() - 1 - i];
        ret += (r - '0') * base;
        base *= 8;
    }
    return ret;
}

string tenToNine(unsigned ll n)
{
    unsigned ll base = 1;
    string ret = "";
    REP(i, 100)
    {
        ret = to_string(n % 9) + ret;
        n = n / 9;
        if (n == 0)
            break;
    }
    return ret;
}

string hachigo(string n)
{

    REP(i, n.size())
    {
        if (n[i] == '8')
            n[i] = '5';
    }
    return n;
}

int main()
{
    string N;
    cin >> N;
    ll n;
    unsigned ll K;
    cin >> K;

    REP(i, K)
    {
        n = eightToten(N);
        N = tenToNine(n);
        N = hachigo(N);
    }

    cout << N << endl;

    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}