#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

queue <int > Q[100];
vector <int > Tap;
bool inUse[100];
int main()
{
    int N, K, Timeline[100];
    scanf("%d %d",&N,&K);

    for(int i=0; i<K; i++) {
        scanf("%d",&Timeline[i]);
        Q[Timeline[i]].push(i);
    }
    for(int i=0; i<K; i++) {
        Q[i].push(999);
    }
    int p=0,ans=0;
    for(int i=0; i<K; i++) {
        if(inUse[Timeline[i]]) Q[Timeline[i]].pop();
        else if(p<N) {
            Tap.push_back(Timeline[i]);
            inUse[Timeline[i]]=true;
            Q[Timeline[i]].pop();
            p++;
        }
        else {
            int index=0,Max=Q[Tap[0]].front();
            for(int j=1; j<N; j++) {
                if(Max < Q[Tap[j]].front()) {
                    index=j;
                    Max = Q[Tap[j]].front();
                }
            }
            inUse[Tap[index]]=false;
            Tap[index] = Timeline[i];
            inUse[Tap[index]]=true;
            Q[Tap[index]].pop();
            ans++;

        }

    }
    printf("%d",ans);
    return 0;
}
