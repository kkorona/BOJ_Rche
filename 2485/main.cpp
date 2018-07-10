#include <iostream>
#include <vector>
using namespace std;

int gcd(int x,int y) {
    int a = x;
    int b = y;
    int c = a%b;
    while(c != 0) {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

int main()
{
    int N;
    cin >> N;
    vector <int> treePoint(N,0);
    for(int i=0; i<N; i++)
        cin >> treePoint[i];
    int nans = treePoint[1] - treePoint[0];
    for(int i=2; i<N; i++) {
        static int cur;
        cur = treePoint[i] - treePoint[i-1];
        nans = gcd(nans,cur);
    }

    int ans = 0;
    for(int i=1; i<N; i++) {
        ans += (treePoint[i] - treePoint[i-1]) / nans - 1;
    }
    cout << ans;
    return 0;
}
