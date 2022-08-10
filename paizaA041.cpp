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
#define REPR(i, n) for(long long i = (n) - 1; i >= 0; i--)

typedef struct 
{
    int x;
    int y;
    int w;
    int h;
    bool isSecret;
} DOCUMENT;

bool isIn(DOCUMENT d, int x, int y)
{
    if(d.x < x && x < d.x + d.w
       && d.y < y && y < d.y + d.h)
       {
           return true;
       }
       else
       {
           return false;
       }
       
}

bool overwrap(DOCUMENT d1, DOCUMENT d2)
{
    bool ret = false;

    if(isIn(d1,d2.x,d2.y)
    || isIn(d1,d2.x+d2.w,d2.y)
    || isIn(d1,d2.x,d2.y+d2.h)
    || isIn(d1,d2.x+d2.w,d2.y+d2.h)
    || isIn(d2,d1.x,d1.y)
    || isIn(d2,d1.x+d1.w,d1.y)
    || isIn(d2,d1.x,d1.y+d1.h)
    || isIn(d2,d1.x+d1.w,d1.y+d1.h))
    {
        ret = true;
    }

    return ret;
}

int main()
{
    int N; //書類の数
    cin >> N;

    int ans = 0; 
    DOCUMENT docs[N];
    REP(i, N)
    {
        int x,y,w,h,s;
        cin >> x >> y >> w >> h >> s;
        bool sec = (s==1);
        docs[i] = (DOCUMENT){x,y,w,h,sec};

        if (sec)
        {
            ans++;
        }
        else
        {
            REP(j, i)
            {
                if(docs[j].isSecret && overwrap(docs[j], docs[i]))
                {
                    ans++;
                    docs[i].isSecret = true;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}