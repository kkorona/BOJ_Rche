#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector < int > rope(N,0);
    for(int i=0; i<N; i++)
        cin >> rope[i];

    sort(rope.begin(),rope.end());
    reverse(rope.begin(),rope.end());
    int ans = 0, sum = 0;
    for(int i=0; i<N; i++) {
        ans = max(ans,rope[i]*(i+1));
    }

    cout << ans;

    return 0;
}
