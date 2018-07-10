#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class meeting {
public:
    int st,ed;
    meeting(int st=0,int ed=0) : st(st),ed(ed) {};
    bool operator < (const meeting& rhs) const {
        if(ed != rhs.ed) return ed < rhs.ed;
        else return st < rhs.st;
    }
};

int main()
{
    int N;
    cin >> N;
    vector < meeting > M(N);
    for(int i=0; i<N; i++) {
        int st,ed;
        cin >> st >> ed;
        M[i] = meeting(st,ed);
    }
    sort(M.begin(),M.end());
    meeting cur = M[0];
    int ans = 1;
    for(int i=1; i<N; i++) {
        if(cur.ed <= M[i].st) {
            cur = M[i];
            ans++;
        }
    }

    cout << ans;
    return 0;
}
