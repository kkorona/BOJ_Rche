#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int Data[55],N,M,K,standing[55],referee_stand=2;
set <int > s;

int main()
{

    scanf("%d%d%d",&N,&M,&K);

    for(int i=0; i<K; i++)
        scanf("%d",&Data[i]);

    if(M>=K){
        for(int i=0; i<K; i++) printf("1");
        return 0;
    }

    if(M > 0) standing[0]=1;
    if(M > 1) standing[K-1]=1;
    s.insert(0); s.insert(K-1);

    while(referee_stand < M) {
        for(set<int>::iterator it=s.begin(); it!=s.end() && referee_stand < M; it++) {
            set<int>::iterator i=it;
            int lo=*i,hi=*(++i);
            int mid=(lo+hi)/2;

            int consider1=lower_bound(Data,Data+K,mid)-Data;
            int consider2=upper_bound(Data,Data+K,mid)-Data;

            if(consider1+consider2 >= 2*mid) { //consider1�� ��հŸ��� ������ ��
                standing[consider1]=1;
                s.insert(Data[consider1]);
                referee_stand++; //������ �ش� ��ġ�� ����ִ´�.
            }
            else { // consider2�� ��հŸ��� ������ ��
                standing[consider2]=1;
                s.insert(Data[consider2]);
                referee_stand++; //������ �ش� ��ġ�� ����ִ´�.
            }

        }
    }

    for(int i=0; i<K; i++) printf("%d",standing[i]);

    return 0;
}
