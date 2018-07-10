#include <iostream>

using namespace std;

int main()
{
    int aw=0,bw=0,a,b;
    int N;
    cin >> N;
    while(N--) {
        cin >> a >> b;
        if(a > b) aw++;
        if(a < b) bw++;
    }
    cout << aw << " " << bw;
    return 0;
}
