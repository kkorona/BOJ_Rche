#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class pillar {
public:
    int x,y;
    pillar (int x=0,int y=0) : x(x), y(y) {}
    bool operator < (const pillar& rhs) const {
        return x < rhs.x;
    }
};

int main()
{
    int N,ans=1e9;
    cin >> N;
    vector <int> L(1002,0);
    vector <int> R(1002,0);
    vector < pillar > P(N);
    for(pillar& p : P) {
        cin >> p.x >> p.y;
    }

    sort(P.begin(),P.end());

    int curMax = 0,cnt=1;
    for(int i=0; i<N; i++) {
        while(cnt <= P[i].x) {
            L[cnt] = L[cnt-1] + curMax;
            cnt++;
        }
        curMax = max(curMax, P[i].y);
    }
    while(cnt <= 1000) {
        L[cnt] = L[cnt-1] + curMax;
        cnt++;
    }

    curMax = 0, cnt = 1000;

    for(int i=N-1; i>=0; i--) {
        while(cnt >= P[i].x + 1) {
            R[cnt] = R[cnt+1] + curMax;
            cnt--;
        }
        curMax = max(curMax,P[i].y);
    }
    while(cnt > 0) {
        R[cnt] = R[cnt+1] + curMax;
        cnt--;
    }


    for(int i=1; i<=1000; i++) {
        ans = min(ans,L[i]+R[i]);
    }

    cout << ans;

    return 0;
}
