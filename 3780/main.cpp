#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector <int> djs;
vector <int> dist;

int getDist(int i,int j) {
    return ((int)abs(i-j))%1000;
}

void init(int N) {
    for(int i=1; i<=N; i++) {
        djs[i] = i;
        dist[i] = 0;
    }
}

int Find(int x) {
    if(djs[x] == x) {
        dist[x] = 0;
    }
    else {
        int t = Find(djs[x]);
        dist[x] += dist[djs[x]];
        djs[x] = t;
    }
    return djs[x];
}

void Union(int u,int v) {
    dist[u] = getDist(u,v);
    djs[u] = v;
}


int main()
{
    int T;
    scanf("%d",&T);
    djs.resize(20001,0);
    dist.resize(20001,0);
    int N,i,j;
    char order;
    bool continueState = true;
    while(T--) {
        scanf("%d",&N);
        init(N);
        continueState = true;
        while(continueState) {
            scanf(" %c",&order);
            switch(order) {
            case 'E':
                scanf("%d",&i);
                Find(i);
                printf("%d\n",dist[i]);
                break;
            case 'I':
                scanf("%d %d",&i,&j);
                Union(i,j);
                break;
            default: continueState = false;
            }
        }
    }
    return 0;
}
