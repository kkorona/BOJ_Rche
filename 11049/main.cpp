#include <cstdio>
#include <algorithm>

using namespace std;

int Matrix_var[502];
int D[501][501];
int N;

const int INF = 0x7fffffff;

int main()
{
    scanf("%d",&N);
    scanf("%d",&Matrix_var[0]);
    for(int i=1; i<N; i++) {
        int x;
        scanf("%d",&x);
        scanf("%d",&Matrix_var[i]);
    }
    scanf("%d",&Matrix_var[N]);


    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            D[i][j]=INF;
            for(int k=i; k<=j; k++) {
                D[i][j]=min(D[i][j],D[i][k]+D[k+1][j]+(Matrix_var[i]*Matrix_var[k+1]*Matrix_var[j+1]));
            }
        }
    }

    printf("%d",D[0][N-1]);
    return 0;
}
