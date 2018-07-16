#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N,M;
    cin << N << M;
    vector <int> T(N+1,0);
    vector <int> unavail(N+1,0);
    for(int i=0; i<M; i++) {
        int x;
        cin << x;
        unavail[x]=1;
    }
    T[0]=0;
    for(int i=1; i<=N; i++) {
        T[i] = T[i-1] + 10000;
        bool get3day = true;
        for(int j=i-1; j>=i-2; j--)
            if(unavail[j] == -1) get3day = false;
        if(get3day) {
            T[i] = min(T[i],T[i-3] + 27000);
        }

        bool get5day = true;
        for(int j=i-1; j>=i-4; j--)
            if(unavail[j] == -1) get5day = false;
        if(get5day) {
            T[i] = min(T[i],T[i-5] + 37000);
        }

    }

    return 0;
}
