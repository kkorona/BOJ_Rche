#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

class point {
public:
    int y,x;
    point(int y = 0,int x = 0) : y(y), x(x) {}
    bool operator < (const point& rhs) const{
        if(y != rhs.y) return y < rhs.y;
        return x < rhs.x;
    }
};

int pointDistance(const point& A,const point& B) {
    return (A.y-B.y) * (A.y-B.y) + (A.x - B.x) * (A.x - B.x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int N;
    cin >> N;
    vector < point > data(N);
    for(int i=0; i<N; i++) {
        cin >> data[i].x >> data[i].y;
    }

    sort(data.begin(),data.end(),[&](const point& A,const point& B){ return A.x < B.x; });
    set <point> cand;
    int d = 210000000;
    int startPoint = 0;
    for(int i=0; i<N; i++) {
        for(int j=startPoint; j<i; j++) {
            if((data[i].x-data[j].x)*(data[i].x-data[j].x) > d) {
                cand.erase(data[j]);
                startPoint++;
            }
            else
                break;
        }
        int dist = (int)sqrt((double)d) + 1;
        point lo = point(-1e6,data[i].y - dist);
        point hi = point(1e6, data[i].y + dist);
        auto l = cand.lower_bound(lo);
        auto r = cand.upper_bound(hi);
        for(auto it = l; it!=r; it++) {
            d = min(d, pointDistance(*it,data[i]));
        }
        cand.insert(data[i]);
    }
    cout << d;


    return 0;
}
