#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector < int > price1(M,0);
    vector < int > price6(M,0);

    for(int i=0; i<M; i++) {
        cin >> price6[i] >> price1[i];
    }

    sort(price1.begin(),price1.end());
    sort(price6.begin(),price6.end());

    int p1 = price1[0],p6 = price6[0];
    if(p1 * 6 < p6) {
        cout << p1 * N;
    }
    else {
        if(p1 * (N%6) < p6) {
            cout << p6 * (N/6) + p1 * (N%6);
        }
        else {
            cout << p6 * ((N+6-(N%6)) / 6);
        }
    }

    return 0;
}
