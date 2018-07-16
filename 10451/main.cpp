#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int t,N,Arr[1005],visit[1005];

void DFS(int x,const vector <int>& Graph) {
    visit[x]=1;
    int next=Graph[x];
    if(visit[next] == 0) DFS(next,Graph);
}

int main()
{
    scanf("%d",&t);
    for(;t>0; t--) {
        scanf("%d",&N);
        for(int i=0; i<N; i++) {
            scanf("%d",&Arr[i]);
            Arr[i]--;
        }
        vector <int> Connexion(Arr,Arr+N);
        int ans=0;
        memset(visit,0,sizeof(int)*N);

        for(int i=0; i<N; i++) {
            if(!visit[i]) {
                DFS(i,Connexion); ans++;
            }
        }

        printf("%d\n",ans);

    }

    return 0;
}
