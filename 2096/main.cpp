#include <cstdio>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

void Dump(vector <int>& P) {
    for(int i=1; i<=3; i++)
        printf("%d ",P[i]);
    printf("\n");
}

int main()
{
    int N;
    scanf("%d",&N);
    int rr[3]={-1,0,1};

    vector <int > Input(4,0);
    vector <int > T_Max(4,0);
    vector <int > prev_Max(4,0);
    vector <int > T_Min(4,INF);
    vector <int > prev_Min(4,INF);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=3; j++) {
            scanf("%d",&Input[j]);
            prev_Max[j]=T_Max[j];
            prev_Min[j]=T_Min[j];
        }

        for(int j=1; j<=3; j++) {
            if(i == 1) {
                T_Max[j]=Input[j];
                T_Min[j]=Input[j];
                continue;
            }

            T_Max[j]=0;
            T_Min[j]=INF;

            for(int k=0; k<3; k++) {
                int index=j+rr[k];
                if(bchk(1,index,4)) {
                    T_Max[j]=max(T_Max[j],prev_Max[index]+Input[j]);
                    T_Min[j]=min(T_Min[j],prev_Min[index]+Input[j]);
                }
            }
        }
        /*

        Dump(T_Max);
        Dump(T_Min);
        printf("\n---------------\n");
        */
    }


    printf("%d %d",max(T_Max[3],max(T_Max[1],T_Max[2])),min(T_Min[3],min(T_Min[1],T_Min[2])));

    return 0;
}
