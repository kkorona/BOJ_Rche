#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool boundaryCheck(int lo,int tar,int hi) {
    return lo <= tar && tar <= hi;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie();

    int N,M,T,K;
    cin >> N >> M >> T >> K;

    vector < pair < int,int > > diamonds(T);

    for(int i=0; i<T; i++)
        cin >> diamonds[i].first >> diamonds[i].second;

    sort(diamonds.begin(),diamonds.end());

    int ans = 0;
    pair <int,int> ansPoint;
    for(auto d1 : diamonds) {
        for(auto d2 : diamonds) {
            static int sy,sx,fy,fx,cnt;
            cnt = 0;
            sy = min(d1.first,d2.first);
            sx = min(d1.second,d2.second);
            fy = sy + K;
            fx = sx + K;
            for(auto td : diamonds) {
                if(boundaryCheck(sy,td.first,fy) && boundaryCheck(sx,td.second,fx)) cnt++;
            }
            if(cnt > ans) {
                ans = cnt;
                if(fx > M) fx = M;
                if(fy > N) sy -= fy - N;
                ansPoint = make_pair(sy,fx);
            }
        }
    }

    cout << ansPoint.first << " " << ansPoint.second << "\n" << ans;

    return 0;
}
