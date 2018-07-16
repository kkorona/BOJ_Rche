#include <cstdio>

using namespace std;

int Data[60][2],Rank[60];

int main()
{
    int n;

    scanf("%d",&n);


    for(int i=0; i<n; i++) {
        scanf("%d %d",&Data[i][0], &Data[i][1]);
        Rank[i]=1;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            if(Data[j][0] >Data[i][0] && Data[j][1] > Data[i][1]) Rank[i]++;
    }
    for(int i=0; i<n; i++)
        printf("%d ",Rank[i]);

    return 0;
}
