#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define Identify(A,B) strcmp(A,B)==0

queue <int > Queue;

int main()
{
    char Command[7];
    int Input,n;

    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%s",Command);
        if(Identify(Command,"push")) {
                scanf("%d",&Input);
                Queue.push(Input);
        }
        else if(Identify(Command,"front")) {
            (Queue.empty()) ? printf("-1\n") :printf("%d\n",Queue.front());
        }
        else if(Identify(Command,"back")) {
            (Queue.empty()) ? printf("-1\n") :printf("%d\n",Queue.back());
        }
        else if(Identify(Command, "size")) {
            printf("%d\n",Queue.size());
        }
        else if(Identify(Command,"empty")) {
            printf("%d\n",Queue.empty());
        }
        else if(Identify(Command, "pop")) {
            if(Queue.empty()) printf("-1\n");
            else {
                printf("%d\n",Queue.front());
                Queue.pop();
            }
        }
    }
    return 0;
}
