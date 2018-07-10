#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int a,b,c;
    long long res;
    char str[100];
    int Check[10]={0,};

    scanf("%d %d %d",&a,&b,&c);
    res=a*b*c;
    sprintf(str,"%lld",res);
    for(int i=0; i<strlen(str); i++) Check[str[i]-'0']++;

    for(int i=0; i<10; i++) printf("%d\n",Check[i]);

    return 0;
}
