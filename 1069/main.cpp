#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int X,Y,D,T;
    cin >> X >> Y >> D >> T;
    double dist = sqrt(X*X + Y*Y);
    int jump = dist/D;
    double leftDist = dist - jump * D;
    double ans = dist;
    ans = min(ans, leftDist + jump* T);
    if(jump > 0) ans = min(ans, (jump+1) * T * 1.0);
    else {
        ans = min(ans, D-leftDist + T);
        if(dist < D) ans = min(ans, T * 2.0);
    }
    printf("%.10lf",ans);
    return 0;
}
