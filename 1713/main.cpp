#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class portrait {
public:
    int time, votes,index;
    portrait(int time=0, int votes=0, int index = 0) : time(time),votes(votes),index(index) {}
    bool operator < (const portrait& rhs) const {
        return index < rhs.index;
    }
};

int main()
{
    int N,M;
    cin >> N >> M;
    vector < portrait > portraits;

    int _size = 0;

    while(M--) {

        //for(auto p : portraits) cout << p.index << " ";
        //cout << endl;
        static int input;
        static bool flag;
        flag = false;
        cin >> input;
        for(auto& p : portraits) {
            if(p.index == input) {
                flag = true;
                p.votes ++;
            }
        }
        if(flag) continue;

        if(_size < N) {
            portraits.push_back(portrait(-M,1,input));
            _size ++;
        }
        else {
            int least = 1e9,idx,curTime;
            for(int i=0; i<N; i++) {
                portrait p = portraits[i];
                if(p.votes < least) {
                    least = p.votes;
                    idx = i;
                    curTime = p.time;
                }
                else if(p.votes == least && p.time < curTime) {
                    idx = i;
                    curTime = p.time;
                }
            }
            portraits[idx] = portrait(-M,1,input);
        }
    }
    sort(portraits.begin(),portraits.end());
    for(auto p : portraits) cout << p.index << " ";
    return 0;
}
