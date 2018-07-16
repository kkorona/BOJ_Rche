#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int lo = 1, hi = 10000;
    int N;
    cin >> N;
    vector <int> Data(N,0);
    for(int i=0; i<N; i++)
        cin >> Data[i];

    sort(Data.begin(),Data.end());
    if(N%2 == 1) cout << Data[N/2];
    else cout << Data[N/2-1];
    return 0;
}
