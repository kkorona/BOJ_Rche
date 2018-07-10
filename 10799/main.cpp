#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

stack <int > Stack;

char Data[100005];

int main()
{
    scanf("%s",Data);
    int n=strlen(Data),res=0;

    for(int i=0; i<n; i++) {
        if(Data[i] == ')') {
            if(Data[i-1] == '(') {
                res+=Stack.size()-1;
                res--;
            }
            Stack.pop();
        }
        else {
            Stack.push(1);
            res++;
        }
    }

    printf("%d",res);

    return 0;
}
