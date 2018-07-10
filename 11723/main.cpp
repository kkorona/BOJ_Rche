#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class Set {
    int _set[21];
public :
    Set() {
        empty();
    }
    void empty() {
        memset(_set,0,sizeof(_set));
    }
    void check(int x) {
        if(_set[x] == 1)  printf("1\n");
        else printf("0\n");

    }
    void remove(int x) {
        _set[x]=0;
    }
    void add(int x) {
        _set[x]=1;
    }
    void toggle(int x) {
        if(_set[x] == 1) remove(x);
        else add(x);
    }
    void all() {
        for(int i=1; i<=20; i++)
            add(i);
    }
};

int main()
{
    Set pset;
    int N;
    scanf("%d",&N);

    char Order[20];
    int x;

    while(N--) {
        scanf("%s",Order);
        if(strcmp(Order,"all") != 0 && strcmp(Order,"empty") != 0) scanf(" %d",&x);

        if(strcmp(Order,"add") == 0) pset.add(x);
        if(strcmp(Order,"check") == 0) pset.check(x);
        if(strcmp(Order,"remove") == 0) pset.remove(x);
        if(strcmp(Order,"toggle") == 0) pset.toggle(x);
        if(strcmp(Order,"all") == 0) pset.all();
        if(strcmp(Order,"empty") == 0) pset.empty();
    }

    return 0;
}
