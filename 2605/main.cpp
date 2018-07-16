#include <cstdio>

using namespace std;

void Dump(int* p,int Size) {
    for(int i=1; i<=Size; i++)
        printf("%d ",p[i]);
    printf("\n");
}

int main()
{
    int students[101]={0,},n;

    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        int number;
        scanf("%d",&number);
        int st_point=i-number;
        //printf("%d\n",st_point);
        for(int j=i; j>st_point; j--)
            students[j]=students[j-1];
        students[st_point]=i;
        //Dump(students,i);
    }

    Dump(students,n);

    return 0;
}
