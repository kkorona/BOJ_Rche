#include <iostream>

using namespace std;

int main()
{
    int n,a,b;
    cin >> n;
    for(a=0,b=1; n--; b+=a,a=b-a);
    cout << a;

    return 0;
}
