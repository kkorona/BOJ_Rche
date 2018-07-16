#include <cstdio>
#include <algorithm>

using namespace std;

struct User {
    char name[105];
    int age;
} Data[100005];

bool cmp (const User& A, const User& B) {
    if(A.age != B.age) return A.age < B.age;
    return false;
}

int main()
{

    int n;

    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d %s",&Data[i].age,Data[i].name);
    }

    stable_sort(Data,Data+n,cmp);

    for(int i=0; i<n; i++) {
        printf("%d %s\n",Data[i].age,Data[i].name);
    }

    return 0;
}
