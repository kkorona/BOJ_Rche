#include <cstdio>
#include <list>
#include <cstring>
using namespace std;

list <char > List;

int main()
{
    char state[100005];
    int N;

    scanf("%s",state);

    int state_size=strlen(state);

    for(int i=0; i<state_size; i++)
        List.push_back(state[i]);

    scanf("%d",&N);
    list <char>::iterator it = List.end();

    for(int i=0; i<N; i++) {
        char order;
        scanf("\n%c",&order);
        if(order == 'L') {
            if(it != List.begin()) it--;
        }
        if(order == 'D') {
            if(it != List.end()) it++;
        }
        if(order == 'B') {
            if(!List.empty() && it != List.begin())  {
                it--;
                it=List.erase(it);
            }
        }
        if(order == 'P') {
            char temp;
            scanf(" %c",&temp);
            List.insert(it,temp);
        }
        /*printf("%c :",order);
        for(list <char>::iterator cit=List.begin(); cit!=List.end(); cit++)
            printf("%c",(*cit));
        printf("\n");
        */
    }
    for(it=List.begin(); it!=List.end(); it++)
        printf("%c",(*it));
    return 0;
}
