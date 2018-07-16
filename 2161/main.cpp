#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int N;
    queue <int> Q;

    scanf("%d",&N);

    for(int i=1; i<=N; i++)
        Q.push(i);

    while(!Q.empty()) {
        printf("%d ",Q.front());
        Q.pop();
        int temp=Q.front();
        Q.pop();
        Q.push(temp);
    }

    return 0;
}
