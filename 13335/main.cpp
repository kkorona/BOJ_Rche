#include <iostream>
#include <queue>
using namespace std;

queue < int > Left;
queue < pair <int,int> > Bridge;

int main()
{

    int time=0,n,w,l;
    int cur_weight=0, arrived=0;

    cin >> n >> w >> l;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        Left.push(x);
    }

    while(arrived < n) {
        time++;
        auto cur = Bridge.front();
        int load = cur.first;
        int start = cur.second;
        if(!Bridge.empty() && time - start == w) {
            cur_weight -= load;
            Bridge.pop();
            arrived++;
        }
        if(!Left.empty() && cur_weight + Left.front() <= l) {
            Bridge.push(make_pair(Left.front(),time));
            cur_weight += Left.front();
            Left.pop();
        }
    }
    cout << time;

    return 0;
}
