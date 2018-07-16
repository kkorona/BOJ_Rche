#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int N=9,S=100,Data[9],ans,num,finished;
int check[9];

priority_queue <int, vector<int>, greater<int > > answer;

void add(int depth) {
    if(finished) return;
    if(depth == N) {
        //printf("%d / %d \n",ans,num);
        if(ans == S && num == 7) {
            for(int i=0; i<9; i++)
                if(check[i]) answer.push(Data[i]);
            finished=1;
            //printf("\n");
        }
        return;
    }
    ans+=Data[depth];
    check[depth]=1;
    num++;
    add(depth+1);
    ans-=Data[depth];
    check[depth]=0;
    num--;
    add(depth+1);
}

int main()
{

    for(int i=0; i<N; i++)
        scanf("%d",&Data[i]);

    add(0);

    while(!answer.empty()) {
            printf("%d\n",answer.top());
    answer.pop();
    }

    return 0;
}
