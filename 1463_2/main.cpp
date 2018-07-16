/*
 * date : 2017/08/02
 */


#include <cstdio>
#include <queue>
using namespace std;

const int INF=1e6;

int Memo[INF+1];
queue <int > Q;
int N;

inline bool bchk(int low,int target,int high) {
    return low<=target && target <= high;
}

void Make() {
    Q.push(1);
    Memo[1]=0;

    while(!Q.empty()) {
        int cur=Q.front();
        Q.pop();
        if(bchk(1,cur*3,INF) && Memo[cur*3] == 0) {
            Memo[cur*3]=Memo[cur]+1;
            Q.push(cur*3);
        }
        if(bchk(1,cur*2,INF) && Memo[cur*2] == 0) {
            Memo[cur*2]=Memo[cur]+1;
            Q.push(cur*2);
        }
        if(bchk(1,cur+1,INF) && Memo[cur+1] == 0) {
            Memo[cur+1]=Memo[cur]+1;
            Q.push(cur+1);
        }
    }
}

int main()
{

    scanf("%d",&N);

    Make();
    printf("%d",Memo[N]);
    return 0;
}
