#include <cstdio>

using namespace std;

int main()
{
    int n,H,W,N;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d %d %d",&H,&W,&N);
        int k=N%H,p=N/H;
        if(k==0) {
            k=H;
            p--;
        }
        printf("%d\n",p+k*100+1);
    }
    return 0;
}
