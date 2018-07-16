#include <cstdio>
#include <queue>

using namespace std;

int D[1000001];
queue <int > Q,T;
void dfs() {

    Q.push(1);
    T.push(1);
    while(!Q.empty()) {
        int index=Q.front(),t_index=T.front();
        //printf("%d %d\n",index,t_index);
        if(index <= 1000000 && D[index] == 0) {
            D[index]=t_index;
            Q.push(index*2); T.push(t_index+1);
            Q.push(index*3); T.push(t_index+1);
            Q.push(index+1); T.push(t_index+1);
        }
        Q.pop(); T.pop();
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    dfs();
    printf("%d",D[n]-1);
    return 0;
}
