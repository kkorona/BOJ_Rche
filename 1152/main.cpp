#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char T[1000001];
    gets(T);
    int cnt=0;
    char *p=strtok(T," ");
    while(p != NULL) {
        p=strtok(NULL," ");
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}
