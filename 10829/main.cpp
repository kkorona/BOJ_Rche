#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

stack <long long > Stack;

int main() {

    long long x;
    scanf("%lld",&x);
    while(x>0) {
        Stack.push(x%2);
        x/=2;
    }
    while(!Stack.empty()) {
        printf("%lld",Stack.top());
        Stack.pop();
    }
    return 0;
}

