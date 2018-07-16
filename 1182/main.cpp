#include <cstdio>

using namespace std;

int N,S,Data[25],ans,res;

void add(int depth) {
    if(depth == N) {
        if(ans == S) res++;
        return;
    }
    ans+=Data[depth];
    add(depth+1);
    ans-=Data[depth];
    add(depth+1);
}

int main()
{

    scanf("%d%d",&N,&S);
    for(int i=0; i<N; i++)
        scanf("%d",&Data[i]);

    add(0);
    if(S == 0) res--;
    printf("%d",res);

    return 0;
}
