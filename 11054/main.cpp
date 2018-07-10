#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    int N;
    scanf("%d",&N);
    vector <int > Data(N,0);
    vector <int > Forward, F_D(N,0);
    vector <int > Reverse, R_D(N,0);

    for(int i=0; i<N; i++)
        scanf("%d",&Data[i]);

    for(int i=0; i<N; i++) {
        int it=lower_bound(Forward.begin(),Forward.end(),Data[i]) - Forward.begin();
        if(it != Forward.size()) Forward.erase(Forward.begin()+it);
        Forward.insert(Forward.begin()+it,Data[i]);
        F_D[i]=it+1;
    }
    for(int i=N-1; i>=0; i--) {
        int it=lower_bound(Reverse.begin(),Reverse.end(),Data[i]) - Reverse.begin();
        if(it != Reverse.size()) Reverse.erase(Reverse.begin()+it);
        Reverse.insert(Reverse.begin()+it,Data[i]);
        R_D[i]=it+1;
    }



    int ans=F_D[0]+R_D[0]-1;
    for(int i=0; i<N; i++)
        ans=max(ans,F_D[i]+R_D[i]-1);

    printf("%d",ans);

    return 0;
}
