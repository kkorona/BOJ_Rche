#include <cstdio>
#include <cstring>
using namespace std;

int main() {

    int N,j;

    char str[51],strr[51];

    scanf("%d",&N);

    for(int i=0; i<N; i++) {
        scanf("%s",strr);
        if(i==0) {
            strcpy(str,strr); continue;
        }
        for(j=0; j<strlen(str); j++)
            if(str[j]!=strr[j]) str[j]='?';

    }

    printf("%s",str);

    return 0;
}
