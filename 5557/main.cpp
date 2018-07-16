#include <cstdio>

using namespace std;

int N,value[101];
long long T[101][21];

inline bool boarder(long long target) {
    return ((0<= target) && (target <= 20));
}

int main()
{
    scanf("%d",&N);

    for(int i=1; i<=N; i++)
        scanf("%d",&value[i]);

    T[1][value[1]]=1;

    for(int i=2; i<N; i++) {
        for(int j=0; j<=20; j++) {
            if(T[i-1][j] > 0) {
                int k=j-value[i];
                if(boarder(k)) T[i][k]+=T[i-1][j];
                k=j+value[i];
                if(boarder(k)) T[i][k]+=T[i-1][j];
            }
        }
    }
    /*
    for(int i=1; i<N; i++) {
        for(int j=0; j<=20; j++) {
            printf("%3d",T[i][j]);
        }
        printf("\n");
    }
    */

    printf("%lld",T[N-1][value[N]]);

    return 0;
}
