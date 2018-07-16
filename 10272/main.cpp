#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

double dis(vector <double>& X, vector <double>& Y,double a,double b)  { return sqrt((X[a]-X[b])*(X[a]-X[b])+(Y[a]-Y[b])*(Y[a]-Y[b])); }

double solve(vector < vector <double> >& dp,vector <double>& X, vector <double>& Y, int l,int r) {
    //printf("solve(%d,%d)\n",l,r);
    if(r == N) return dis(X,Y,l,r);
    if(dp[l][r] > 0) return dp[l][r];
    return dp[l][r]=min(solve(dp,X,Y,l,r+1)+dis(X,Y,r,r+1),solve(dp,X,Y,r,r+1)+dis(X,Y,l,r+1));
}

int main()
{

    int T;
    scanf("%d",&T);

    while(T--) {
        scanf("%d",&N);

        vector < vector < double > > dp(N+1);
        vector <double> Y(N+1,0);
        vector <double> X(N+1,0);

        for(int i=1; i<=N; i++)
            scanf("%lf%lf",&Y[i],&X[i]);

        dp.resize(N+1);
        for(int i=1; i<=N; i++)
            dp[i].resize(N+1,0);

        printf("%g\n",solve(dp,X,Y,1,1));

    }


    return 0;
}
