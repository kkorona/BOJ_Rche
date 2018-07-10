#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Name {
    char name[100];
} Data[20020];

bool cmp(const Name& a,const Name& b) {
    int len_a=strlen(a.name);
    int len_b=strlen(b.name);

    if(len_a != len_b) return len_a < len_b;
    return strcmp(a.name,b.name) < 0;
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++) scanf("%s",Data[i].name);

    sort(Data,Data+n,cmp);

    for(int i=0; i<n; i++) {
        if(i>0)
            if(strcmp(Data[i].name,Data[i-1].name) == 0)
                continue;
        printf("%s\n",Data[i].name);
    }
    return 0;
}
