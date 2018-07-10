#include <cstdio>

using namespace std;

int main()
{
    int A,B,C;

    scanf("%d %d %d",&A,&B,&C);
    int a=(A+B)%C,b= (A%C + B%C)%C, c=(A*B)%C, d=(A%C * B%C)%C;

    printf("%d\n%d\n%d\n%d\n",a,b,c,d);
    return 0;
}
