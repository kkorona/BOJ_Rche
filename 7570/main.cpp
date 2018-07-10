#include <iostream>
#include <vector>
using namespace std;

vector <int> cnt(1000001,0);
int main()
{
    int N,x;
    cin >> N;
    int maxLength = 0;
    for(int i=0; i<N; i++) {
        cin >> x;
        cnt[x] = cnt[x-1]+1;
        maxLength = max(maxLength,cnt[x]);
    }
    cout << N - maxLength;
    return 0;
}
