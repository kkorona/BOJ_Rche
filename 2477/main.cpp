#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int K;
    vector < pair < int,int > > edges;
    pair < int,int > verticalMax(0,0);
    pair < int,int > horizentalMax(0,0);
    cin >> K;
    for(int i=0; i<6; i++) {
        static int dir,len;
        cin >> dir >> len;
        edges.push_back(make_pair(len,dir));
    }

    for(int i=0; i<6; i++) {
        if(edges[i].second >= 3) {
            if(edges[i].first > verticalMax.first) {
                verticalMax = make_pair(edges[i].first,i);
            }
        }
        else {
            if(edges[i].first > horizentalMax.first) {
                horizentalMax = make_pair(edges[i].first,i);
            }
        }
    }

    int lo = verticalMax.second, hi = horizentalMax.second;
    if(lo > hi) swap(lo,hi);
    if(lo == 0 && hi == 5) swap(lo,hi);
    int ans = verticalMax.first * horizentalMax.first;
    ans -= edges[(hi+2)%6].first * edges[(hi+3)%6].first;
    cout << ans * K;
    return 0;
}
