#include <cstdio>
#include <queue>

using namespace std;

priority_queue <int > max_heap;

int main()
{
    int n,order;

    scanf("%d",&n);

    for(;n>0; n--) {
        scanf("%d",&order);
        if(order == 0) {
            if(max_heap.empty()) printf("0");
            else {
                printf("%d",max_heap.top());
                max_heap.pop();
            }
            printf("\n");
        }
        else max_heap.push(order);
    }

    return 0;
}
