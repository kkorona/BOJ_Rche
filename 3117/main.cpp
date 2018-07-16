#include <cstdio>

using namespace std;

int student[100001],recommand[100001][50],N,K,M;

int main()
{
    scanf("%d%d%d",&N,&K,&M);
    for(int i=0; i<N; i++) scanf("%d",&student[i]);
    for(int i=1; i<=K; i++) scanf("%d",&recommand[i][0]);
    for(int i=0; i<31; i++)
        for(int j=1; j<=K; j++)
            recommand[j][i+1]=recommand[recommand[j][i]][i];

    for(int i=0; i<N; i++) {
        int ans=student[i];
        int m=M-1;
        for(int i=0; i<31; i++) {
            if(m & 1<<i)
                ans=recommand[ans][i];
        }
        printf("%d ",ans);
    }
    return 0;
}
