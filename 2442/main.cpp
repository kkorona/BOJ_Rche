#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++)
            printf(" ");
        for(int j=1; j<=i*2-1; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
