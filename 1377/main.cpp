#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector < pair<int,int> > input(N);
    for(int i=0; i<N; i++) {
        cin >> input[i].first;
        input[i].second=i;
    }
    sort(input.begin(),input.end());
    int ans = 0;
    for(int i=0; i<N; i++) {
        ans = max(ans, input[i].second-i);
    }
    cout << ans+1;

    return 0;
}
