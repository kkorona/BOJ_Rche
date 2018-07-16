#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int N;
    long long sum = 0;
    cin >> N;
    vector <int> Data(N,0);
    for(int i=0; i<N; i++) {
        cin >>Data[i];
        sum += Data[i];
    }
    sort(Data.begin(),Data.end());
    int ans1 = (N%2 == 0) ? Data[N/2-1] :Data[N/2];
    int ans2;
    int ave1 = sum / N;
    int ave2 = ave1 + 1;

    long long diff1=0, diff2=0;
    for(int i=0; i<N; i++) {
        diff1 += (Data[i] - ave1) * (Data[i] - ave1);
        diff2 += (Data[i] - ave2) * (Data[i] - ave2);
    }
    ans2 = (diff1 <= diff2) ? ave1 : ave2;
    cout << ans1 << " " << ans2;
    return 0;
}
