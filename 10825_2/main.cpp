#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct stud {
    char name[51];
    int kor,math,eng;
} Data[100002];

bool cmp(stud a,stud b) {

    if(a.kor != b.kor) return a.kor > b.kor;
    if(a.eng != b.eng) return a.eng < b.eng;
    if(a.math != b.math) return a.math > b.math;
    if(strcmp(a.name,b.name) != 0) return (strcmp(a.name,b.name) < 0);
    return true;
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
            scanf("%s %d %d %d",Data[i].name,&Data[i].kor,&Data[i].eng,&Data[i].math);
    }

    sort(Data,Data+n,cmp);

    for(int i=0; i<n; i++) {
        printf("%s\n",Data[i].name);
    }
    return 0;
}
