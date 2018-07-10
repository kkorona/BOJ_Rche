#include <iostream>

using namespace std;

int data[21];
int N,S,ans;

void Track(int index) {
    static int sum=0;
    if(sum == S) {
        ans++;
    }

    for(int i=index+1; i<=N; i++) {
        sum+=data[i];
        Track(i);
        sum-=data[i];
    }
}

int main() {
    cin >> N >> S;

    for(int i=1; i<=N; i++)
        cin >> data[i];

    Track(0);

    if(S == 0) ans--;
    cout << ans;

    return 0;
}
