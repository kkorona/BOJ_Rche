#include <iostream>

using namespace std;

int main()
{
    int X;
    cin >> X;
    int x = 1, y = 1;
    X--;
    int diff = 1;
    while(X-->0) {
        x -= diff;
        y += diff;
        if(y < 1) {
            y++;
            diff = -diff;
        }
        if(x < 1) {
            x++;
            diff = -diff;
        }
    }
    cout << x << "/" << y;
    return 0;
}
