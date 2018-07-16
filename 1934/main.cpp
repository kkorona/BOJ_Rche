#include <iostream>

using namespace std;

long long lcm(int a,int b) {
    long long x,y,z;
    x=a; y=b;
    while(y!=0) {
        z=x%y;
        x=y;
        y=z;
    }
    return a*b/x;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        long long a,b;
        cin >> a >> b;
        cout << lcm(a,b) << endl;
    }
    return 0;
}
