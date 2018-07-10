#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << (N+2)/3 << endl;
    int ncount = 0, count2 = 0;
    for(int i=2; i<=N; i++) {
        if(N%i == 0) {
            ncount++;
            N/=i;
            if(i == 2) count2++;
            i = 1;
        }
    }
    cout << ncount - (count2/2);
    return 0;
}
