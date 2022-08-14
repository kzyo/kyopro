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

typedef struct
{
    int depth;
    int pos;
} POS;

enum
{
    FIRST,
    MIDDLE,
    LAST,
};

int main()
{
    ll k,s,t;
    cin >> k >> s >> t;

    ll len[k];
    len[0] = 3;
    REP(i, k) {
        if (i == 0) continue;
        
        len[i] = 3 + 2*len[i-1];
    }
    
    deque<POS> stck {}; 
    ll now_s = s;
    int dep = k - 1;
    REP(i, k) {
        ll ln = len[dep];
        ll st = 1;
        ll mid = ln/2 + 1;
        ll end = ln;
        bool completed = false;
        
        if (now_s == mid || now_s == st || now_s == end) {
            completed = true;
        }

        int pos = -1;
        if (now_s == st) {
            pos = FIRST;
        }
        else if (now_s <= mid) {
            pos = MIDDLE;
        }
        else if (now_s <= end) {
            pos = LAST;
            now_s -= ln / 2;
        }
        
        stck.push_back((POS){dep, pos});
        
        if (completed) break;
        
        now_s--;
        dep--;
    }
    
    int out_len = t - s + 1;
    string out_chars = "ABC";
    REP(i,out_len) {
        POS p = stck.back();
        stck.pop_back();

        if (p.depth < 0) {
            i--;
            continue;
        }
        
        cout << out_chars[p.pos];

        if (p.pos < LAST) {
            stck.push_back((POS){p.depth, p.pos + 1});
            stck.push_back((POS){p.depth - 1, FIRST});
        }
    }

    return 0;
}