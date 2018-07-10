#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

#define Identify(A,B) strcmp(A,B)==0

stack <int > Stack;

int main()
{
    char Command[6];
    int Input,n;

    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%s",Command);
        if(Identify(Command,"push")) {
                scanf("%d",&Input);
                Stack.push(Input);
        }
        else if(Identify(Command,"top")) {
            (Stack.empty()) ? printf("-1\n") :printf("%d\n",Stack.top());
        }
        else if(Identify(Command, "size")) {
            printf("%d\n",Stack.size());
        }
        else if(Identify(Command,"empty")) {
            printf("%d\n",Stack.empty());
        }
        else if(Identify(Command, "pop")) {
            if(Stack.empty()) printf("-1\n");
            else {
                printf("%d\n",Stack.top());
                Stack.pop();
            }
        }
    }
    return 0;
}
