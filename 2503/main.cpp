#include <iostream>
#include <vector>
using namespace std;

typedef pair < int,int > Score;
vector < Score > L;
vector < int > call;
int N,ans=0;
Score cmp(int _x,int _y) {
    int x = _x, y = _y;
    int xcnt[10] = {0, }, ycnt[10] = {0, };
    int strike=0,ball=0;
    while(x > 0) {
        if(x%10 == y%10) strike++;
        xcnt[x%10]=1;
        ycnt[y%10]=1;
        x/=10;
        y/=10;
    }
    for(int i=0; i<10; i++)
        if(xcnt[i] & ycnt[i]) ball++;
    ball -= strike;
    return make_pair(strike,ball);
}

void check(int K) {
    bool isMatch = true;
    for(int i=0; i<N; i++) {
        if(L[i] != cmp(call[i],K)) {
            isMatch = false;
            break;
        }
    }
    if(isMatch) {
        ans++;
    }
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++) {
        int e,s,b;
        cin >> e >> s >> b;
        call.push_back(e);
        L.push_back(make_pair(s,b));
    }



    for(int i=123; i<=987; i++) {
        int p1 = i%10, p2 = (i/10)%10, p3 = i/100;
        if(p1 == p2 || p2 == p3 || p3 == p1) continue;
        if(p1 == 0 || p2 == 0 || p3 == 0) continue;
        check(i);
    }
    cout << ans;
    return 0;
}
