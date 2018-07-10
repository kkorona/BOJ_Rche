#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ans,N,M;
struct Name {
    char name[24];
}Data[500004];

bool Check[500004];

int cmp(const Name& A,const Name& B) {
    int temp=strcmp(A.name,B.name);
    if(temp != 0) return ((temp<0) ? (1):(0));
    return 2;
}

void B_Search(const Name& key) {
    int lo=0,hi=N-1;
    while(lo<=hi) {
        int mid=(lo+hi)/2;
        if(cmp(Data[mid],key) == 0) hi=mid-1;
        else if(cmp(Data[mid],key) == 1) lo=mid+1;
        else {
            ans++;
            Check[mid]=1;
            return;
        }
    }
    return;
}

int main()
{
    Name temp;

    scanf("%d %d",&N,&M);

    for(int i=0; i<N; i++) scanf("%s",Data[i].name);

    sort(Data,Data+N,cmp);

    for(int i=0; i<M; i++) {
        scanf("%s",temp.name);
        B_Search(temp);
    }
    printf("%d\n",ans);
    for(int i=0; i<N; i++) if(Check[i]) printf("%s\n",Data[i].name);

    return 0;
}
