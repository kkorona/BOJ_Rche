#include <cstdio>
#include <cstring>

using namespace std;

int ZR,ZC,R,C;

int main()
{
   scanf("%d%d%d%d",&R,&C,&ZR,&ZC);
   for(int i=0; i<R; i++) {
    char temp[51];
    scanf("%s",temp);
    for(int s=0; s<ZR;s++) {
        for(int j=0; j<strlen(temp); j++)
            for(int k=0; k<ZC; k++)
                printf("%c",temp[j]);
        printf("\n");
    }
   }
    return 0;
}

