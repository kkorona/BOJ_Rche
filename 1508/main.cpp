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

            if(consider1+consider2 >= 2*mid) { //consider1이 평균거리에 근접할 때
                standing[consider1]=1;
                s.insert(Data[consider1]);
                referee_stand++; //심판을 해당 위치에 집어넣는다.
            }
            else { // consider2이 평균거리에 근접할 때
                standing[consider2]=1;
                s.insert(Data[consider2]);
                referee_stand++; //심판을 해당 위치에 집어넣는다.
            }

        }
    }

    for(int i=0; i<K; i++) printf("%d",standing[i]);

    return 0;
}
