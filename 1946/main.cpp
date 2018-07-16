#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Rank {
public :
    int ar,br;

    Rank(const int AR = 0, const int BR = 0) {
        ar=AR;
        br=BR;
    }

    bool operator <(const Rank& R) const {
        if(ar != R.ar) return ar < R.ar;
        return br < R.br;
    }
};

int main()
{
    int T;
    scanf("%d",&T);

    while(T--) {
        int N, a_input[100001], b_input[100001];

        vector <Rank > Data;
        scanf("%d",&N);
        for(int i=0; i<N; i++) {
            scanf("%d%d",&a_input[i],&b_input[i]);
            Data.push_back(Rank(a_input[i],b_input[i]));
        }

        sort(Data.begin(),Data.end());

        int ans=1;
        int defb=Data[0].br;
        for(int i=1; i<N; i++) {
            if(Data[i].br < defb) {
                ans++;
                defb=Data[i].br;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
