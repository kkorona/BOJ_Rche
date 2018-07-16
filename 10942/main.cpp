#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);

    vector <int > Data(N,0);

    for(int i=0; i<N; i++)
        scanf("%d",&Data[i]);

    vector < vector < bool > > Palin(N);
    for(int i=0; i<N; i++)
        Palin[i].resize(N,false);

    for(int i=0; i<N; i++)
        Palin[i][i]=true;

    for(int i=0; i<N; i++) {
        for(int j=1; i-j >= 0 && i+j <N; j++) {
            if(Palin[i-j+1][i+j-1] == true && Data[i-j] == Data[i+j])
                Palin[i-j][i+j]=true;
        }
        if(Data[i] == Data[i+1]) {
            Palin[i][i+1] = true;
            for(int j=1; i-j >= 0 && i+j+1 <N; j++) {
                if(Palin[i-j+1][i+j] && Data[i-j] == Data[i+1+j])
                    Palin[i-j][i+1+j]=true;
            }
        }
    }

    int T;
    scanf("%d",&T);
    while(T--) {
        int st,ed;
        scanf("%d%d",&st,&ed);
        st--;
        ed--;
        int ans= ((Palin[st][ed] ? (1) : (0)));
        printf("%d\n",ans);
    }

    return 0;
}
