#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long lo = 1 ,hi = 1000000;
int N,M,K,L;

vector < pair < int,int > > wrong;

bool boundarycheck(int lo,int tar,int hi) {
    return lo <= tar && tar <= hi;
}

int verify(long long tar) {
    static int sx,fx;
    vector <int> covered(L,0);
    int coverCount = 0;
    int ret = 0;
    for(int i=0; i<L; i++) {
        if(covered[i] == 0) {
            sx = wrong[i].first;
            fx = wrong[i].first + tar - 1;
            for(int j=0; j<L; j++) {
                if(covered[j] == 0 && boundarycheck(sx,wrong[j].first,fx)) {
                    covered[j] = 1;
                    coverCount++;
                }
            }
            ret++;
        }
    }

    if(coverCount == L) return ret;
    else return 1e9;
}

int main()
{
    cin >> N >> M >> K >> L;
    wrong.resize(L);

    for(int i=0; i<L; i++) {
        cin >> wrong[i].second >> wrong[i].first;
        if(wrong[i].second > lo) lo = wrong[i].second;
    }

    sort(wrong.begin(),wrong.end());

    while(lo <= hi) {
        static long long mid;
        mid = (lo+hi)/2;
        //cout << mid << " " << K << endl;
        if(verify(mid) <= K) {
            hi = mid-1;
        }
        else lo = mid+1;
    }

    cout << lo;


    return 0;
}
