#include <cstdio>
#include <algorithm>

using namespace std;

int Wine[10001],T[10001];
int N;

int main() {

    scanf("%d",&N);

    for(int i=1; i<=N; i++)
        scanf("%d",&Wine[i]);

    T[N+1]=0;
    T[N]=Wine[N];
    T[N-1]=Wine[N]+Wine[N-1];
    for(int i=N-2; i>=1; i--) {
        T[i]=max(T[i+1],Wine[i]+T[i+2]);
        T[i]=max(T[i],Wine[i]+Wine[i+1]+T[i+3]);
    }

    printf("%d",T[1]);

    return 0;
}
