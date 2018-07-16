#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    pair <int,int> winner(0,0);
    vector <int> input(6,0);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=5; j++) {
            cin >> input[j];
        }
        int cur = 0;
        for(int j1=1; j1<=3; j1++) {
            for(int j2=j1+1; j2<=4; j2++) {
                for(int j3=j2+1;j3<=5;j3++) {
                    cur = max(cur,(input[j1]+input[j2]+input[j3])%10);
                }
            }
        }
        winner = max(winner,make_pair(cur,i));
    }
    cout << winner.second;
    return 0;
}
