#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class arrival {
public :
    double time;
    int lane,id;
    bool operator <(const arrival &A) const {
        if(time != A.time) return time < A.time;
        if(lane != A.lane) return lane < A.lane;
        return id < A.id;
    }
};

int main()
{

    int n;
    scanf("%d",&n);
    vector <arrival > v(2*n);

    for(int i=0; i<n; i++) {
        int lane,speed,start;
        scanf("%d %d %d",&start,&lane,&speed);
        v[i].time=(double)(0-start)*speed;
        v[i+n].time=(double)(1-start)*speed;
        v[i].lane=lane; v[i+n].lane=lane;
        v[i].id=-i-1; v[i+n].id=i+1;
    }

    sort(v.begin(),v.end());

    multiset<int > M;

    int cnt=0,prev=0;
    M.insert(0);
    for(int i=0; i<v.size(); i++) {
        if(v[i].id > 0) {
            M.erase(M.lower_bound(v[i].lane));
        }
        else {
            M.insert(v[i].lane);
        }
        int cur=*M.begin();
        printf("%d\n",cur);
        if(prev != cur) cnt++;
        prev=cur;
    }
    printf("%d",cnt);
    return 0;
}
