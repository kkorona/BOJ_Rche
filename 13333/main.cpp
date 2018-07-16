#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    int N;
    cin >> N;
    vector <int> Data(N+1,0);
    for(int i=1; i<=N; i++)
        cin >> Data[i];
    int ans=0;
    sort(Data.begin(),Data.end());

    for(int k=N; k>=0; k--) {
        if(Data[N-k+1] >= k && Data[N-k] <= k) {
            ans=k;
            break;
        }
    }

    cout << ans;
    return 0;
}
