#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char Data[64]; int ans=0;
    scanf("%s",Data);
    for(int i=0; i<strlen(Data); i++) {
        if(Data[i] == Data[i+1]) ans+=5;
        else ans+=10;
    }
    printf("%d",ans);
    return 0;
}
