#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main()
{

    int N,M;
    cin >> N >> M;
    vector < vector < int > > stud(N,vector<int>(M,0));
    for(int i=0; i<N; i++) {
        static int input;
        for(int j=0; j<M; j++) {
            cin >> input;
            stud[i][j] = input;
        }
        sort(stud[i].begin(),stud[i].end());
    }

    priority_queue < int,vector<int>,greater<int> > pq;

    int curmax = 0;

    for(int i=0; i<N; i++) {
        pq.push(stud[i][0]);
        curmax = max(curmax,stud[i][0]);
    }
    int _size = N;

    while(_size == N) {

    }

    return 0;
}
