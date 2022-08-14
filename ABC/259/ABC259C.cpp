#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define REP(i, n) for(long long i = 0; i < (n); i++)
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

vector<pair<char, int>> counted(string str) {
    vector<pair<char, int>> ret = {};
    char pre = 'a';
    int count = 0;
    REP(idx, str.length()) {
        if (str[idx] == pre) {
            count++;
            continue;
        }

        ret.push_back({pre, count});
        pre = str[idx];
        count = 1;
    }
    ret.push_back({pre, count});

    return ret;
}

int main()
{
    string S, T;
    cin >> S >> T;

    auto s = counted(S);  
    auto t = counted(T);  
    
    bool isOK = true;

    if (s.size() != t.size()) {
        isOK = false;
    } else {
        REP(idx, s.size()) {
            if (s[idx].first != t[idx].first) {
                isOK = false;
                break;
            }
            if (s[idx].second > t[idx].second) {
                isOK = false;
                break;
            }
            if (s[idx].second == 1 && t[idx].second > 1) {
                isOK = false;
                break;
            }
        }
    }

    if (isOK) { cout << "Yes" << endl;}
    else { cout << "No" << endl;}
    
    cout << fixed << setprecision(20); // 小数点以下20桁まで表示
    return 0;
}
