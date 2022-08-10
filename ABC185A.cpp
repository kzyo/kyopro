#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <deque>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)

int main()
{
    int ans = 1000;
    int a;

    REP(i,4) 
    {
        cin >> a;
        ans = min(a, ans);
    }

    cout << ans << endl;

    return 0;
}