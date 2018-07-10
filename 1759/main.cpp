#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

char password[17],Data[17];
int used[17],L,C;

int momCheck(char c) {
    char Mom[6]="aeiou";
    for(int i=0; i<5; i++) {
        if(c == Mom[i]) return 1;
    }
    return 0;
}

void BruteForce(int prev, int level, int son, int mom) {
    if(level == L) {
        if(son < 2 || mom < 1) return;
        password[level]='\0';
        printf("%s\n",password);
    }

    for(int i=prev+1; i<C; i++) {
        if(!used[i]) {
            password[level]=Data[i];
            used[i]=1;
            int k=momCheck(Data[i]);
            BruteForce(i,level+1,son+1-k,mom+k);
            used[i]=0;
        }
    }

}

int main()
{
    scanf("%d%d",&L,&C);
    for(int i=0; i<C; i++) {
        scanf(" %c",&Data[i]);
    }

    sort(Data,Data+C);
    BruteForce(-1,0,0,0);


    return 0;
}
