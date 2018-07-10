#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class point {
public:
    int y,x;
    point(int y=0,int x=0) : y(y), x(x) {}
    bool operator < (const point& rhs) const {
        return x < rhs.x;
    }
};

int main() {

    int N;
    cin >> N;

    vector < point > b(N);
    vector < int > T(N);

    for(int i=0; i<N; i++) {
        cin >> b[i].x >> b[i].y;
        b[i].y = abs(b[i].y);
    }
    sort(b.begin(),b.end());

    int curmax = b[0].y;
    for(int i=0; i<N; i++) {
        curmax = max(curmax, b[i].y);
        T[i] = max(curmax * 2, b[i].x - b[0].x);
    }

    for(int i=1; i<N; i++) {
        curmax = b[i].y;
        for(int j=i; j>0; j--) {
            curmax = max(curmax, b[j].y);
            int val = max(curmax * 2, b[i].x - b[j].x);
            T[i] = min(T[i],T[j-1]+val);
        }
    }
    cout << T[N-1];

    return 0;
}
