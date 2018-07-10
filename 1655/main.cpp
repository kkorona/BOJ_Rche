#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

priority_queue < int > minH;
priority_queue < int, vector<int>, greater<int> > maxH;

int main()
{
    int N, minHs = 0, maxHs = 0;
    scanf("%d",&N);
    int x;
    scanf("%d",&x);
    minH.push(x); minHs++;
    printf("%d\n",x);
    for(int i=2; i<=N; i++) {
        scanf("%d",&x);
        if(x > minH.top()) {
            maxH.push(x); maxHs++;
            if(minHs < maxHs) {
                minH.push(maxH.top()); minHs++;
                maxH.pop(); maxHs--;
            }
        }
        else {
            minH.push(x); minHs++;
            if(minHs - 1 > maxHs) {
                maxH.push(minH.top()); maxHs++;
                minH.pop(); minHs--;
            }
        }
        printf("%d\n",minH.top());
    }
    return 0;
}
