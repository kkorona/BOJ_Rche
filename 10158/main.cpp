#include <iostream>

using namespace std;

int main()
{
    int w,h,p,q;
    int t;
    cin >> w >> h >> p >> q >> t;
    int dy=t%(2*h), dx=t%(2*w);

    p+=dx;
    if(p > w) p=-(p-w)+w;
    if(p < 0) p=-p;
    q+=dy;
    if(q > h) q=-(q-h)+h;
    if(q < 0) q=-q;

    cout << p << " " << q;
    return 0;
}
