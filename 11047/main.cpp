#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int C_input[10], N,K;

    scanf("%d%d",&N,&K);
    for(int i=0; i<N; i++)
        scanf("%d",&C_input[i]);

    vector <int > Coins(C_input,C_input+N);

    int ans=0;

    for(int i=N-1; i>=0 && K > 0; i--) {
        while(K>=C_input[i]) {
            K-=C_input[i];
            ans++;
        }
    }

    printf("%d",ans);

    return 0;
}
