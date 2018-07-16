#include <iostream>
#include <cstdio>

using namespace std;

double dp[1000001];

double ans(int N) {
    if(N < 1) return 0;
    double& ret = dp[N];
    if(ret != 0) return ret;
    if(N == 1) return ret = 1;
    else return ret = (ans(N-6)+ans(N-5)+ans(N-4)+ans(N-3)+ans(N-2)+ans(N-1)+6)/6;
}

int main()
{
    int N;
    cin >> N;
    printf("%.9lf",ans(N));

    return 0;
}
