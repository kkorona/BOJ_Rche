#include <iostream>
#include <vector>
using namespace std;
int main() {

    int N,I,M;
    cin >> N >> I >> M;
    vector < pair < int,int > > fish(M);
    for(int i=0; i<M; i++) {
        cin >> fish[i].first >> fish[i].second;
    }

    I /= 2;
    int ans = 0;
    for(auto startFish1 : fish) {
        for(auto startFish2 : fish) {
            static int sy,sx;
            static int target;
            sy = min(startFish1.first,startFish2.first);
            sx = min(startFish1.second,startFish2.second);
            for(int ny = sy + 1, nx = sx + I-1; ny < sy + I; ny++, nx--) {
                target = 0;
                for(auto targetFish : fish) {
                    if(sy <= targetFish.first && targetFish.first <= ny && sx <= targetFish.second && targetFish.second <= nx) {
                        target ++;
                    }
                }
                ans = max(ans,target);
            }
        }
    }
    cout << ans;
    return 0;

}
