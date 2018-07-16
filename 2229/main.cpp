#include <cstdio>
#include <algorithm>
using namespace std;

/*
 * ������ ���ؼ�
 *
 * ���ٹ��� ���ؼ� ���ذ� �� �ȵǾ���.
 * T[i]�� i��° ������� ������ �� �ִ��̶�� �����Ͽ��µ�
 * ���� for(int j=i+1; j<=n; j++) ������ �ݺ�����
 * i��° ������� �������� �������Ƿ� j�� �����ϴ� ���������� ���̺��� �����ϴ� �۾��� �����Ѵ�.
 * ���� ������ ���������� �ƴϹǷ� T[i]�� ���뿡�� �߰��� ����ؾ��� ������ ������
 * ���� 1�������� Ǯ���� ���� knapsack���� ���̶�� �� �� �ִ°� ����.
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
