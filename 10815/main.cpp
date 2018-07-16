#include <cstdio>
#include <set>

using namespace std;

set <int > List;

int main()
{

    int N,M;

    scanf("%d",&N);

    for(int i=0; i<N; i++) {
        int temp;
        scanf("%d",&temp);
        List.insert(temp);
    }

    scanf("%d",&M);
    for(int i=0; i<M; i++) {
        int temp,res;
        scanf("%d",&temp);
        if(List.find(temp) != List.end()) res=1;
        else res=0;
        printf("%d ",res);
    }

    return 0;
}
