#include <cstdio>
using namespace std;
int main()
{
    int table[10][4]={{10},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}};
    int len[10]={1,1,4,4,2,1,1,4,4,2};

    int a,b;
    int t;
    scanf("%d",&t);
    while(t--) {
            scanf("%d %d",&a,&b);
            a%=10;
            b%=len[a];
            printf("%d\n",table[a][b]);
        }
    return 0;
}
