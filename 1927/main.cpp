#include <cstdio>
#include <queue>

using namespace std;

priority_queue < int, vector<int>, greater<int > > min_heap;

int main()
{
    int n,order;

    scanf("%d",&n);

    for(;n>0; n--) {
        scanf("%d",&order);
        if(order == 0) {
            if(min_heap.empty()) printf("0");
            else {
                printf("%d",min_heap.top());
                min_heap.pop();
            }
            printf("\n");
        }
        else min_heap.push(order);
    }

    return 0;
}
