#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class fl0w3r {
public :
    int st,ed;
    fl0w3r(int st=0,int ed=0) : st(st), ed(ed) {};
    bool operator < (const fl0w3r& rhs) const{
        if(st != rhs.st) return st < rhs.st;
        if(ed != rhs.ed) return ed < rhs.ed;
        return false;
    }
    bool isInRange(int target) {
        return (st <= target) && (target < ed);
    }
};
vector < fl0w3r > flowers;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();

    int N;
    cin >> N;
    flowers.resize(N);
    for(int i=0; i<N; i++) {
        static int a,b,x,y;
        cin >> a >> b >> x >> y;
        flowers[i] = fl0w3r(100*a+b,100*x+y);
    }
    sort(flowers.begin(),flowers.end());
    int t1=301,t2 =301;
    int ans = 0;
    for(fl0w3r f : flowers) {
        if(f.ed <= t1) continue;
        if(f.isInRange(t1)) {
            t2 = max(t2,f.ed);
            if(t2 > 1130) {
                ans++;
                break;
            }
        }
        else {
            ans++;
            t1 = t2;
            if(f.isInRange(t1)) {
                t2 = max(t2,f.ed);
            }
            if(t2 > 1130) {
                ans++;
                break;
            }
        }
    }
    if(t2 > 1130) cout << ans;
    else cout << 0;
    return 0;
}
