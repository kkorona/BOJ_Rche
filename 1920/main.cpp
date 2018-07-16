#include <cstdio>
#include <algorithm>
using namespace std;

int N,M,A[100002],key;

bool bs(int key) {

    int l=0,r=N,m;

    while(l<r) {
        m=(l+r)/2;

        if(key == A[m])
            return true;
        else if(key < A[m])
            r=m;
        else
            l=m+1;
    }
    return false;
}



int main()
{

    scanf("%d",&N);

    for(int i=0; i<N; i++)
        scanf("%d",&A[i]);

    sort(A,A+N);

    scanf("%d",&M);

    for(int i=0; i<M; i++) {
        scanf("%d",&key);
        if(bs(key))
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
