#include <cstdio>
#include <cstring>
using namespace std;

bool censored[105];
int main()
{
    char data[105],censor[]="CAMBRIDGE";

    scanf("%s",data);
    int n=strlen(data);

    for(int i=0; i<n; i++)
        for(int j=0; j<9; j++)
            if(data[i] == censor[j])
                censored[i]=true;

    for(int i=0; i<n; i++)
        if(!censored[i]) printf("%c",data[i]);
    return 0;
}
