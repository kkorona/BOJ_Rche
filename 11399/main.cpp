#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N,input[1001];

    scanf("%d",&N);

    for(int i=0; i<N; i++)
        scanf("%d",&input[i]);

    vector <int > data(input,input+N);

    sort(data.begin(),data.end());

    vector <int > sum(N,0);
    sum[0]=data[0];
    for(int i=1; i<N; i++) {
        sum[i]=sum[i-1]+data[i];
    }

    int ans=0;
    for(int i=0; i<N; i++)
        ans+=sum[i];

    printf("%d\n",ans);

    return 0;
}
