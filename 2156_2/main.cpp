#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);

    vector <int > Data(N+1,0);
    vector <int > T(Data);

    for(int i=0; i<N; i++)
        scanf("%d",&Data[i]);

    T[0]=Data[0];
    T[1]=Data[0]+Data[1];
    T[2]=max(T[0]+Data[2],Data[1]+Data[2]);
    T[2]=max(T[2],T[1]);
    int ans=T[0];
    ans=max(ans,T[1]);
    ans=max(ans,T[2]);
    for(int i=3; i<N; i++) {
        T[i]=max(T[i],T[i-3]+Data[i-1]+Data[i]);
        T[i]=max(T[i],T[i-2]+Data[i]);
        T[i]=max(T[i],T[i-1]);
        ans=max(ans,T[i]);
    }

    printf("%d",ans);
    return 0;
}
