#include <cstdio>
#include <vector>

using namespace std;

vector < int > visit;
vector < int > gotCycle;
vector < int > Next;

int dfs(int index) {
    visit[index]=1;
    int next=Next[index];

    if(visit[next] == 1 && gotCycle[next] != 0) {
        gotCycle[index]=-1;
        return -1;
    }
    else if(next == index) {
        gotCycle[index]=1;
        return -1;
    }
    else if(visit[next] == 1) {
        gotCycle[index]=1;
        return next;
    }

    int p=dfs(next);
    if(p == -1) {
        gotCycle[index]=-1;
        return -1;
    }
    else if(p == index) {
        gotCycle[index]=1;
        return -1;
    }
    else {
        gotCycle[index]=1;
        return p;
    }

}

int main()
{
    int T;
    scanf("%d",&T);

    while(T--) {

        visit.clear();
        Next.clear();
        gotCycle.clear();

        int N,ans=0;

        scanf("%d",&N);
        visit.resize(N+1,0);
        gotCycle.resize(N+1,0);
        Next.resize(N+1);

        for(int i=1; i<=N; i++) {
            int x;
            scanf("%d",&x);
            Next[i]=x;
        }
        for(int i=1; i<=N; i++) {
            if(!visit[i])
                dfs(i);
        }

        for(int i=1; i<=N; i++) {
            //printf("%d ",gotCycle[i]);
            if(gotCycle[i] == -1)
                ans++;
        }

        printf("%d\n",ans);

    }


    return 0;
}
