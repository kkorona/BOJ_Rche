#include <cstdio>

using namespace std;

int main()
{
    int inc=1,dec,load=0,Max=-0x7ffffff;

    while(inc > 0) {
        scanf("%d %d",&dec,&inc);
        load-=dec;
        load+=inc;
        if(Max < load) Max=load;
    }

    printf("%d",Max);

    return 0;
}
