#include <cstdio>
#include <algorithm>
using namespace std;

/*
 * 문제에 대해서
 *
 * 접근법에 대해서 이해가 잘 안되었다.
 * T[i]를 i번째 사람까지 묶었을 때 최댓값이라고 정의하였는데
 * 따라서 for(int j=i+1; j<=n; j++) 이하의 반복문은
 * i번째 사람까지 최적으로 묶었으므로 j가 지정하는 사람들까지의 테이블을 갱신하는 작업을 수행한다.
 * 조의 개수가 제한조건이 아니므로 T[i]의 내용에서 추가로 고려해야할 사항이 없으며
 * 따라서 1차원으로 풀리는 것이 knapsack과의 차이라고 볼 수 있는것 같다.
 */

 const int INF = 0x7fffffff;

int main()
{

    int n;
    int data[1001],T[1001];

    scanf("%d",&n);
    data[0]=0;
    for(int i=1; i<=n; i++) {
        scanf("%d",&data[i]);
        T[i]=-INF;
    }

    T[0]=0;

    for(int i=0; i<n; i++) {
        int Max=-INF;
        int Min=INF;
        for(int j=i+1; j<=n; j++) {
            Max=max(Max,data[j]);
            Min=min(Min,data[j]);
            T[j]=max(T[j],T[i]+Max-Min);
        }
    }

    printf("%d",T[n]);

    return 0;
}
