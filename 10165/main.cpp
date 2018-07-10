#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set <int> Q;

class event {
public :
    int id,time,type;
    event(int _id = 0,int _time = 0,int _type = 0) : id(_id), time(_time), type(_type) {}
    bool operator < (const event& rhs) const {
        if(time != rhs.time) return time < rhs.time;
        return type < rhs.type;
    }
};

int main()
{
    int N,M;
    cin >> N >> M;
    vector < event > E;
    vector < int > essential(M,0);
    vector < int > isdivided(M,0);

    for(int i=0; i<M; i++) {
        int t1,t2;
        cin >> t1 >> t2;
        if(t1 > t2) {
            E.push_back(event(i,t1,-1));
            E.push_back(event(i,N,2));
            E.push_back(event(i,0,-1));
            E.push_back(event(i,t2,2));
        }
        else {
            E.push_back(event(i,t1,-2));
            E.push_back(event(i,t2,1));
        }
    }

    sort(E.begin(),E.end());

    for(int i=0, _size = E.size(); i<_size; i++) {
        if(E[i].type < 0) {

        }
        else if(E)
    }

    return 0;
}
