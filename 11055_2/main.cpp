#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N,ans;
    scanf("%d",&N);

    vector <int > Data(N,0);
    vector <int > D(N,0);

    for(int i=0; i<N; i++)
        scanf("%d",&Data[i]);

    ans=D[0]=Data[0];

    for(int i=1; i<N; i++) {
        D[i]=Data[i];
        for(int j=i-1; j>=0; j--) {
            if(Data[j] < Data[i]) {
                D[i]=max(D[i],Data[i]+D[j]);
            }
        }
        ans=max(ans,D[i]);
    }
    printf("%d",ans);
    return 0;
}
