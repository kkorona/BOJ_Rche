#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

#define MAX 32001

vector <int > List[MAX],order;

priority_queue <int, vector<int>, greater<int> > Q;

int N,M,indegree[MAX],visit[MAX];

int main()
{

    scanf("%d %d",&N,&M);

    for(int i=0; i<M; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        List[a].push_back(b);
        indegree[b]++;
    }

    for(int i=0; i<=N; i++)
        if(indegree[i] == 0)  {
                Q.push(i);
                visit[i]=1;
        }

    while(!Q.empty()) {

        int index=Q.top();
        order.push_back(index);
        Q.pop();
        for(int j=0; j<List[index].size(); j++) {
            int k=List[index][j];
            indegree[k]--;
            if(indegree[k] == 0 && visit[k] == 0) {
                visit[k]=1;
                Q.push(k);
            }
        }
    }

    for(int i=0; i<order.size(); i++)
        printf("%d ",order[i]);

    return 0;
}
