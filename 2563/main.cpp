#include <cstdio>

using namespace std;

int Board[105][105];

int main()
{
    int a,b,n,cnt=0;

    scanf("%d",&n);

    for(int i=0; i<n; i++){
        scanf("%d %d",&a,&b);
        for(int j=a; j<a+10; j++)
            for(int k=b; k<b+10; k++) {
                if(Board[j][k] == 0) {
                        Board[j][k]=1; cnt++;
                }
            }
    }

    printf("%d",cnt);

    return 0;
}
