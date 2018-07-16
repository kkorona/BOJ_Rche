#include <cstdio>

using namespace std;

inline int pow(int x,int p) {
    int ret=1, t=p;
    while(t--) ret*=x;
    return ret;
}

void hanoi(int N,int st,int ed, int po) {

    if(N == 0) return;

    //N-1개를 st에서 po로

    hanoi(N-1, st, po, ed);

    //N번째를 st에서 ed로

    printf("%d %d\n",st,ed);

    //N-1개를 po에서 ed로

    hanoi(N-1,po,ed,st);
}

int main()
{

    int N;
    scanf("%d",&N);
    printf("%d\n",pow(2,N)-1);
    hanoi(N,1,3,2);

    return 0;
}
