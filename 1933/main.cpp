#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Event {
public :
    int x,y,type;

    bool operator <(const Event &E) const {
        if(x != E.x) return x<E.x;
        return type<E.type;
    }
};

int main()
{

    int N;
    scanf("%d",&N);
    vector <Event > v(2*N);

    for(int i=0; i<N; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[i].x=a; v[i+N].x=c;
        v[i].y=b; v[i+N].y=b;
        v[i].type=-i-1; v[i+N].type=i+1;
    }

    sort(v.begin(),v.end());

    int before=0;
    multiset <int > M;
    M.insert(0);
    for(int i=0; i<v.size(); i++) {
        if(v[i].type < 0) {
            M.insert(v[i].y);
        }
        else {
            M.erase(M.lower_bound(v[i].y));
        }
        int now=*M.rbegin();
        if(now != before)
            printf("%d %d ",v[i].x,now);
        before=now;
    }

    return 0;
}
