#include <cstdio>

using namespace std;

int check[30];

int main()
{
    int n=28,temp;
    for(int i=0; i<n; i++) {
        scanf("%d",&temp);
        check[temp-1]=1;
    }
    for(int i=0; i<30; i++)
        if(check[i] == 0) printf("%d\n",i+1);
    return 0;
}
