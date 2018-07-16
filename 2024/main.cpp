#include <cstdio>
#include <algorithm>

using namespace std;

int M,N;

class Line {
    public:
    int start,finish;
    bool operator < (const Line& L) {
        if(L.start != start) return start < L.start;
        return finish > L.finish;
    }
} line[100001];


int main()
{
    int st,ed;
    st=ed=1;
    scanf("%d",&M);
    while(!(ed == 0 && st == 0)) {
        scanf("%d%d",&st,&ed);
        line[N].start=st;
        line[N++].finish=ed;
    }
    sort(line,line+N);

    int k=0,ans=0,ptr=0;
    while(k < M && ptr < N) {
        int m=-1e9;
        while(ptr < N && line[ptr].start <= k)
            m=max(m,line[ptr++].finish);
        if(m == -1e9) break;
        ans++;
        k=m;
    }
    printf("%d",k >= M ? ans : 0);


    return 0;
}
